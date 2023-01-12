class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev=INT_MAX,maxprofit=0;
        for(int i : prices){
            maxprofit = max(i-prev,maxprofit);
            prev= min(prev,i);
        }
        return maxprofit;
    }
};