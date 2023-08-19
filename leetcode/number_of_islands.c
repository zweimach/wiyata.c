#include <stdbool.h>
#include <stdlib.h>

#include "number_of_islands.h"

typedef struct UnionFind UnionFind;

struct UnionFind {
    int unique;
    int* roots;
    int* sizes;
};

void union_find_init(UnionFind* u, int size)
{
    u->unique = size;
    u->roots = malloc(sizeof(int) * size);
    u->sizes = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        u->roots[i] = i;
        u->sizes[i] = 1;
    }
}

void union_find_deinit(UnionFind* u)
{
    free(u->roots);
    free(u->sizes);
}

int union_find_find(UnionFind* u, int p)
{
    int root = p;
    while (root != u->roots[root]) {
        root = u->roots[root];
    }
    while (p != root) {
        int next = u->roots[p];
        u->roots[p] = root;
        p = next;
    }
    return root;
}

void union_find_unify(UnionFind* u, int p, int q)
{
    int root_p = union_find_find(u, p);
    int root_q = union_find_find(u, q);
    if (root_p == root_q) {
        return;
    }
    bool cond = u->sizes[root_p] < u->sizes[root_q];
    int src = cond ? root_p : root_q;
    int dst = cond ? root_q : root_p;
    u->sizes[dst] += u->sizes[src];
    u->roots[src] = u->roots[dst];
    u->sizes[src] = 0;
    u->unique -= 1;
}

#define DIRECTION_LEN 4

int DIRECTION_ROW[DIRECTION_LEN] = {1, 0, -1, 0};

int DIRECTION_COL[DIRECTION_LEN] = {0, 1, 0, -1};

static inline int calculate_index(int col, int x, int y)
{
    return col * x + y;
}

int grid_adjacent(char** grid, int x, int y, int row, int col, int pos)
{
    int idx = x + DIRECTION_ROW[pos];
    int idy = y + DIRECTION_COL[pos];
    if (idx < 0 || idy < 0 || idx >= row || idy >= col) {
        return -1;
    }
    if (grid[idx][idy] != '1') {
        return -1;
    }
    return calculate_index(col, idx, idy);
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int row = gridSize, col = gridColSize[0];
    UnionFind u;
    union_find_init(&u, row * col);

    for (int x = 0; x < row; x++) {
        for (int y = 0; y < col; y++) {
            if (grid[x][y] != '1') {
                u.unique -= 1;
                continue;
            }
            int idx = calculate_index(col, x, y);
            for (int pos = 0, idy = 0; pos < DIRECTION_LEN; pos++) {
                if ((idy = grid_adjacent(grid, x, y, row, col, pos)) != -1) {
                    union_find_unify(&u, idx, idy);
                }
            }
        }
    }

    union_find_deinit(&u);
    return u.unique;
}
