class Solution {
public:
    bool canJump(vector<int>& nums) {
       int maxpos=0;
       for(int i=0;i<nums.size();++i){
           maxpos=max(maxpos,nums[i]+i);
           if(maxpos<i+1)break;//cant reach next position
       }
       return maxpos>=nums.size()-1;
    }
};