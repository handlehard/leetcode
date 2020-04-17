#ifdef HH_PRACTISE
#pragma once
#include "practise/preheader.h"
#endif // HH_PRACTISE

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i <= far) {
                far = max(far, i + nums[i]);
                if (far >= nums.size() - 1) return true;
            }
        }
        return false;
    }

    void stub() {
        //vector<int> nums = { 2,3,1,1,4 };
        //vector<int> nums = { 1 };

        vector<int> nums = { 3, 2, 1, 0, 4 };

        cout << (canJump(nums) ? "true" : "false") << endl;
    }
};