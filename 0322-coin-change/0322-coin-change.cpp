class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<vector<int>>& dp, int idx) {

        if(amount == 0) return 0;

        if(idx == coins.size()) return INT_MAX;

        if(dp[idx][amount] != -1)
            return dp[idx][amount];

        int skip = solve(coins, amount, dp, idx+1);

        if(coins[idx] > amount)
            return dp[idx][amount] = skip;

        int temp = solve(coins, amount-coins[idx], dp, idx);

        int take = INT_MAX;

        if(temp != INT_MAX)
            take = 1 + temp;

        return dp[idx][amount] = min(skip, take);
    }

    int coinChange(vector<int>& coins, int amount) {

        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));

        int ans = solve(coins, amount, dp, 0);

        if(ans == INT_MAX) return -1;

        return ans;
    }
};