class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
		permute(nums,0,nums.size()-1,res);
        return res;
    }
    
    void permute(vector<int>& nums, int left, int right, vector<vector<int>> &res){
        if (left == right) res.push_back(nums);
        for (int i = left; i <= right; i++) {
            swap(nums[left], nums[i]);
            permute(nums,left+1,right,res);
            swap(nums[left],nums[i]);
        }
    }
};