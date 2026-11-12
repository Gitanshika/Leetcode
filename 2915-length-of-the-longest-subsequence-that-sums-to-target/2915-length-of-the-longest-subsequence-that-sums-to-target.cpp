class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>>&dp,int idx,int target){
        if(idx==nums.size()){
            if(target==0){
                return 0;
            }
            else{
                return INT_MIN;
            }
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        int skip=solve(nums,dp,idx+1,target);
        if(nums[idx]>target) return dp[idx][target]=skip;
        int temp=solve(nums,dp,idx+1,target-nums[idx]);
        int take=INT_MIN;
        if(temp!=INT_MIN){
            take=1+temp;
        }
        return dp[idx][target]=max(take,skip);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
    int ans= solve(nums,dp,0,target);
    if(ans==INT_MIN){
        return -1;
    }
    else {
        return ans;
    }
    }
};