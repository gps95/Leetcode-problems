class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> map;
        unordered_set<int> set;
        int maximum = nums2[nums2.size()-1];
        set.insert(nums2[nums2.size()-1]);

        for(int i=nums2.size()-2;i>=0;--i){
            if(nums2[i]>maximum){                
                set.insert(nums2[i]);
                maximum=nums2[i];
            } else map.insert({nums2[i],i});
        }

        for(int num:nums1){
            if(set.find(num)!=set.end()) res.push_back(-1);
            else{
                for(int i=map[num]+1;i<nums2.size();++i){
                    if(nums2[i]>num){
                        res.push_back(nums2[i]);break;
                    }
                } 
            }
        }
        return res;
    }
};