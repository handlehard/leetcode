
#ifdef HH_PRACTISE
#pragma once
#include "practise/preheader.h"
#endif // HH_PRACTISE

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

        vector<vector<int>> result;
        for (auto& elem : intervals) {
            if (result.empty()|| elem[0] > result.back()[1]){
                result.push_back(elem);
            }
            else {
                result.back()[1] = max(elem[1], result.back()[1]);
            }
        }
        return result;
    }

    void stub() {
        vector<vector<int>> input = { {1,3},{2,6},{8,10},{15,18} };
        auto result = merge(input);
        for (auto& elem : result) {
            cout << "[" << elem[0] << ", " << elem[1] << "]\n";
        }
    }
};