#include <stdlib.h>

#include "flood_fill.h"

void fill(int row, int col, int** grid, int x, int y, int c1, int c2);

int** floodFill(int** image,
                int imageSize,
                int* imageColSize,
                int sr,
                int sc,
                int color,
                int* returnSize,
                int** returnColumnSizes)
{
    int row = imageSize, col = imageColSize[0];
    int** new_image = malloc(sizeof(int*) * row);
    *returnSize = imageSize;
    *returnColumnSizes = malloc(sizeof(int) * row);
    for (int i = 0; i < row; i++) {
        new_image[i] = malloc(sizeof(int) * col);
        (*returnColumnSizes)[i] = col;
        for (int j = 0; j < col; j++) {
            new_image[i][j] = image[i][j];
        }
    }
    fill(row, col, new_image, sr, sc, new_image[sr][sc], color);
    return new_image;
}

#define DIRECTION_LEN 4

int DIRECTION_ROW[DIRECTION_LEN] = {1, 0, -1, 0};

int DIRECTION_COL[DIRECTION_LEN] = {0, 1, 0, -1};

void fill(int row, int col, int** grid, int x, int y, int c1, int c2)
{
    if (x < 0 || x >= row || y < 0 || y >= col) {
        return;
    }
    if (c1 == c2 || grid[x][y] != c1) {
        return;
    }
    grid[x][y] = c2;
    for (int i = 0; i < DIRECTION_LEN; i++) {
        int idx = x + DIRECTION_ROW[i];
        int idy = y + DIRECTION_COL[i];
        fill(row, col, grid, idx, idy, c1, c2);
    }
}
