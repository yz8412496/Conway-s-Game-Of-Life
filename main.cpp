#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

// 2D Grid size
const int WIDTH = 10;
const int HEIGHT = 20;

// Max iteration
const int MAX_ITER = 10;

// Generation interval in milliseconds
const int GEN_INT = 500;

// Display grid
void printGrid(const std::vector<std::vector<int>>& grid) {
    // Clear screen to simulate the generation
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            std::cout << (grid[i][j] ? "\u25A0" : ".") << " "; // Two states: alive = "■", dead = "."
        }
        std::cout << std::endl;
    }
    // std::cout << std::endl;
}

// Count alive neighbors for a cell
int countNeighbors(const std::vector<std::vector<int>>& grid, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the current cell
            int newX = x + i;
            int newY = y + j;
            if (newX >= 0 && newX < HEIGHT && newY >= 0 && newY < WIDTH) { // Count when cell coordinates are in bounds
                count += grid[newX][newY];
            }
        }
    }
    return count;
}

// Update the grid to the next generation following a set of pre-defined rules
std::vector<std::vector<int>> nextGeneration(const std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> newGrid = grid;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) newGrid[i][j] = 0; // Any live cell with 2 or 3 live neighbors survives
            } else {
                if (neighbors == 3) newGrid[i][j] = 1; // Any dead cell with exactly three live neighbors becomes a live cell
            }
        }
    }
    return newGrid;
}

int main() {
    // Initialize 2D grid as a vector of vectors
    std::vector<std::vector<int>> grid(HEIGHT, std::vector<int>(WIDTH, 0));

    // Initialize as a glider pattern (Two states: alive = 1, dead = 0)
    grid[1][2] = 1;
    grid[2][3] = 1;
    grid[3][1] = 1;
    grid[3][2] = 1;
    grid[3][3] = 1;

    // Generate for a fixed iterations. Use while (true) to populate in an infinite loop
    for (int i = 0; i < MAX_ITER; i++) {
        printGrid(grid);
        grid = nextGeneration(grid);
        std::this_thread::sleep_for(std::chrono::milliseconds(GEN_INT));
    }
    std::cout << "Generation is complete after " << MAX_ITER << " iterations!";
    return 0;
}