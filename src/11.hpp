
#ifdef HH_PRACTISE
#pragma once
#include "practise/preheader.h"
#endif // HH_PRACTISE

class Solution {
public:
    //int maxArea(vector<int>& height) {
    //    int area = 0;
    //    for (int i = 0; i < height.size() - 1; ++i) {
    //        for (int j = i + 1; j < height.size(); ++j) {
    //            int curArea = (j - i) * min(height[i], height[j]);
    //            if (curArea > area) {
    //                area = curArea;
    //            }
    //        }
    //    }
    //    
    //    return area;
    //}

    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int area = 0;
        while (left < right) {
            area = max(area, (right - left) * min(height[left], height[right]));
            if (height[left] <= height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return area;
    }
    
    void stub() {
        vector<int> height = { 1,8,6,2,5,4,8,3,7 };
        cout << maxArea(height) << endl;
    }
};