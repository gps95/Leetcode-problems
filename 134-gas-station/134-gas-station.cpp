class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totgas=0,totcost=0,tank=0,ini=0;
        for(int i=0;i<gas.size();++i){
            totgas+=gas[i];
            totcost+=cost[i];
            tank+=(gas[i]-cost[i]);
            if(tank<0)ini=i+1,tank=0;
        }
        if(totgas<totcost) return -1;
        return ini;
    }
};