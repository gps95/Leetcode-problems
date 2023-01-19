class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ret=0,prefix=0;
        vector<int> count(k);//counts how many remainders
        count[0]=1;
        //we need to work with the remainders
        for(int num:nums){
            //+k to make remainder positive and in range [0,k)
            prefix=(prefix+(num%k)+k)%k;
            ret+=count[prefix]++;
        }
        return ret;
    }
};