class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ini=0,fin=nums.size(),mid;
        while(ini<fin){
            mid=ini + (fin-ini)/2;
            if(nums[mid]<target)ini=mid+1;
            else fin=mid;
        }
        return ini;
    }
};