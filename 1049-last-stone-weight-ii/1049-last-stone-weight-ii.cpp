class Solution {
public:
int solve(vector<int>& stones, vector<vector<int>>& dp, int idx, int target) {
if(target == 0) return true;

if(idx == stones.size()) return false;
if(dp[idx][target] != -1)
    return dp[idx][target];
bool skip = solve(stones, dp, idx+1, target);
if(stones[idx]>target) return dp[idx][target]=skip;
bool  take = solve(stones, dp, idx+1, target-stones[idx]);
return dp[idx][target]=skip ||take;
}
    int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    int sum = 0;

        for(int x : stones) {
            sum += x;
        }
         int target = sum / 2;

        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
int ans = INT_MAX;

for(int j = target; j >= 0; j--) {
    if(solve(stones, dp, 0, j)) {
        ans = min(ans, sum - 2*j);
        break;
    }
}

return ans;
    }
};