
#ifdef HH_PRACTISE
#pragma once
#include "practise/preheader.h"
#endif // HH_PRACTISE

class Solution {
public:
    //int coinChange(vector<int>& coins, int amount) {
    //    if (amount < 0) return -1;
    //    if (amount == 0) return 0;

    //    int result = INT_MAX;
    //    for (auto& i : coins) {
    //        int tmp = coinChange(coins, amount - i);
    //        if (tmp == -1) continue;

    //        result = min(result, tmp + 1);
    //    }
    //    return result == INT_MAX ? -1 : result;
    //}

    //map<int, int> dp;
    //int coinChange(vector<int>& coins, int amount) {
    //    if (amount < 0) return -1;
    //    if (amount == 0) return 0;

    //    if (dp.count(amount)) return dp[amount];

    //    int result = INT_MAX;
    //    for (auto& i : coins) {
    //        int tmp = coinChange(coins, amount - i);
    //        if (tmp == -1) continue;

    //        result = min(result, tmp + 1);
    //    }
    //    dp[amount] = (result == INT_MAX ? -1 : result);
    //    return dp[amount];
    //}

    int coinChange(vector<int>& coins, int amount) {
        // �����СΪ amount + 1����ʼֵҲΪ amount + 1
        vector<int> dp(amount + 1, amount + 1);
        // base case
        dp[0] = 0;
        for (int i = 0; i < dp.size(); i++) {
            // �ڲ� for �������������� + 1 ����Сֵ
            for (int coin : coins) {
                // �������޽⣬����
                if (i - coin < 0) continue;
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }


    void stub() {
        auto start = system_clock::now();

        vector<int> coins = { 181,79,206,169,487,319,262,162,420 };
        int amount = 4409;
        cout << coinChange(coins, amount) << endl;

        // do something...
        auto end = system_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << duration.count() << "ms" << endl;
    }
};