class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ini=0,fin=nums.size(),mid;
        while(ini<fin){
            mid=ini+(fin-ini)/2;
            
            int num = (nums[mid]<nums[0]) == (target<nums[0])? nums[mid]:
            (target<nums[0])?INT_MIN:INT_MAX;
            
            if(num==target)return mid;
            if(num<target) ini=mid+1;
            else fin=mid;
        }
        return -1;
    }
};