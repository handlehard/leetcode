
#ifdef HH_PRACTISE
#pragma once
#include "practise/preheader.h"
#endif // HH_PRACTISE

class Solution {
public:

    //// dfs
    //int numIslands(vector<vector<char>>& grid) {
    //    if (grid.empty()) return 0;

    //    int result = 0;

    //    for (int i = 0; i < grid.size(); ++i) {
    //        for (int j = 0; j < grid[0].size(); ++j) {
    //            if (grid[i][j] == '1') {
    //                dfs(grid, i, j);
    //                result++;
    //            }
    //        }
    //    }
    //    return result;
    //}

    //void dfs(vector<vector<char>>& grid, int r, int c) {
    //    if (!(0 <= r && r < grid.size() && 0 <= c && c < grid[0].size())) {
    //        return;
    //    }

    //    if (grid[r][c] != '1') return;

    //    grid[r][c] = '2';

    //    dfs(grid, r, c - 1);
    //    dfs(grid, r, c + 1);
    //    dfs(grid, r - 1, c);
    //    dfs(grid, r + 1, c);
    //}

    // bfs
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int result = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    queue<pair<int, int>> q;
                    q.push({ i, j });
                    grid[i][j] = '2';
                    while (!q.empty()) {
                        auto node = q.front();
                        q.pop();

                        int r = node.first;
                        int c = node.second;
                        if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                            q.push({ r - 1, c });
                            grid[r - 1][c] = '2';
                        }
                        if (r + 1 < grid.size() && grid[r + 1][c] == '1') {
                            q.push({ r + 1, c });
                            grid[r + 1][c] = '2';
                        }
                        if (c - 1 >= 0 && grid[r][c-1] == '1') {
                            q.push({ r, c-1 });
                            grid[r][c-1] = '2';
                        }
                        if (c + 1 < grid[0].size() && grid[r][c + 1] == '1') {
                            q.push({ r, c + 1 });
                            grid[r][c + 1] = '2';
                        }
                    }
                    result++;
                }
            }
        }
        return result;
    }

    void stub() {
        vector<vector<char>> grid = { {'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'} };

        //vector<vector<char>> grid = { {'1', '1', '0', '0', '0'}, { '1','1','0','0','0' }, { '0','0','1','0','0' }, { '0','0','0','1','1' } };
        cout << numIslands(grid) << endl;
    }
};