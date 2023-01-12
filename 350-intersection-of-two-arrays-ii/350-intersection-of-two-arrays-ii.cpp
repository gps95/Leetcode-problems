class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;//key=number,value=number of ocurrences of said number
        vector<int> res;
        //filling map
        for(int i:nums1){
            map[i]++;
        }
        //getting intersection
        for(int i:nums2){
            if(map.find(i)!=map.end()){
                res.push_back(i);
                if (--map[i]<=0)map.erase(i);
            }
        }
        return res;
    }
};