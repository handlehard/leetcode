
#ifdef HH_PRACTISE
#pragma once
#include "practise/preheader.h"
#endif // HH_PRACTISE

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        dfs(result, "", n, 0, 0);
        return result;
    }
    void stub() {
        auto result = generateParenthesis(3);
        for (auto& elem : result)
            cout << "\"" << elem.c_str() << "\"" << endl;
    }

private:
    void dfs(vector<string>& result, string path, int n, int lc, int rc) {
        if (lc > n || rc > n || lc < rc) return;
        if (lc == n && lc == rc) {
            result.push_back(path);
            return;
        }
        dfs(result, path + "(", n, lc + 1, rc);
        dfs(result, path + ")", n, lc, rc + 1);
    }
};