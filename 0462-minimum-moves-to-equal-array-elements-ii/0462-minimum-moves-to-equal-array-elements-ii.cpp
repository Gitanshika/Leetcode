class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int k=n/2;
        int minsum=0;
        for(int i=0;i<n;i++){
            minsum+=abs(nums[i]-nums[k]);
        }
        return minsum;
    }
};