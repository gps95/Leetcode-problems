class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> map;
        for(int i:nums){
            if(map.find(i) == map.end()) map.insert(i);
            else return true;
        }
        return false;
    }
};