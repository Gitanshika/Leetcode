class Solution {
public:
    int ways(vector<int>& arr, vector<vector<int>>& dp, int target, int idx, int offset) {

        if(idx == arr.size()){
            if(target == 0) return 1;
            return 0;
        }
    
        if(target < -offset || target > offset)
            return 0;
        if(dp[idx][target + offset] != -1)
            return dp[idx][target + offset];

        int add = ways(arr, dp, target - arr[idx], idx + 1, offset);

        int sub = ways(arr, dp, target + arr[idx], idx + 1, offset);

        return dp[idx][target + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;

        for(int num : nums){
            sum += num;
        }

        if(abs(target) > sum) return 0;

        int offset = sum;

        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1));

        return ways(nums, dp, target, 0, offset);
    }
};