class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0]<nums[nums.size()-1]) return nums[0];
        int ini=0,fin = nums.size()-1,mid;
        while(ini<fin){
            mid=((fin-ini)>>1)+ini;
            if(nums[fin]<=nums[mid]) ini=mid+1;
            else fin=mid;
        }
        return nums[ini];
    }
};