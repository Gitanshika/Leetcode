class Solution {
public:
    
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    int n=nums.size();
    vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,INT_MIN));
    for(int i = 0; i <= n; i++) {
    dp[i][0] = 0;
}
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=target;j++){
            int skip=dp[i+1][j];
            int take=INT_MIN;
             if(nums[i]<=j && dp[i+1][j-nums[i]]!=INT_MIN){
                take=1+dp[i+1][j-nums[i]];
             }
            dp[i][j]=max(take,skip);
        }
    }
    if(dp[0][target]==INT_MIN){
        return -1;
    }
    else {
        return dp[0][target];
    }
    }
};