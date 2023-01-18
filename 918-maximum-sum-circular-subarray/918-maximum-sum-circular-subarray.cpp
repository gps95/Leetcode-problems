class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //maxsubarray==Kadanes algorithm, circular is special case
        int sum=0;
        for(int num:nums)sum+=num;
        int currmax=nums[0],currmin=nums[0],bestmax=nums[0],bestmin=nums[0];
        for(int i=1;i<nums.size();++i){
            //normal Kadanes algorithm(max subarray sum)
            currmax = max(currmax+nums[i],nums[i]);
            bestmax = max(bestmax,currmax);
            //Kadanes for min
            currmin = min(currmin+nums[i],nums[i]);
            bestmin = min(bestmin,currmin);
        }
        if(bestmin==sum)return bestmax;
        return max(bestmax,sum-bestmin);
    }
};