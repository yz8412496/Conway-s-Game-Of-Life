## Introduction

Implement the Conway’s Game Of Life algorithm in C++. The Game Of Life is a cellular automaton algorithm. It runs on a universe, which is two-dimensional a grid of cells. Each cell can be in two states: alive or dead. There is an initial state for the universe, which defines alive cells and their positions in the universe. The automaton progresses one step at a time by applying a set of rules to each cell in the universe. There rules are the following: 
1) Any live cell with two or three live neighbors survives;
2) Any dead cell with exactly three live neighbors becomes a live cell;
3) All other live cells die in the next generation. Similarly, all other dead cells stay dead.

## How to run:
Run **main.cpp** directly with C++ compiler. 

Comment following lines to disable screen clearing:
```
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
```

Current code uses a glider pattern to demo but it can be changed to any user-defined patterns:
```
grid[1][2] = 1;
grid[2][3] = 1;
grid[3][1] = 1;
grid[3][2] = 1;
grid[3][3] = 1;
```

Current code simulates with limited iterations as defined in **MAX_ITER**. We can use **while (true){}** to simulate in infinite loop:
```
while (true) {
        printGrid(grid);
        grid = nextGeneration(grid);
        std::this_thread::sleep_for(std::chrono::milliseconds(GEN_INT));
    }
```
