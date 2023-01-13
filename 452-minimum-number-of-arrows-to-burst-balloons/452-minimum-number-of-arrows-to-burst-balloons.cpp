class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int count=1,lastMax=points[0][1];
        for(vector<int> v:points){
            if(lastMax<v[0])count++,lastMax=v[1];
            else lastMax=min(lastMax,v[1]);
        }
        return count;
    }
};