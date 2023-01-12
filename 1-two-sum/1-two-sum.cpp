class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;//key=number,value=position in array nums
        for(int i=0;i<nums.size();++i){
            int numToFind = target - nums[i];
            auto aux=map.find(numToFind);
            if(aux!=map.end()){
                return {i,aux->second};
            }
            map.insert({nums[i],i});//meter en map el actual
        }
        return {-1,-1};
    }
};