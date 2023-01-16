class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool isIntervalInserted = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[0] < intervals[i][0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                isIntervalInserted = true;
                break;
            }
        }
        if (!isIntervalInserted) {
            intervals.push_back(newInterval);
        }
        
        vector<vector<int>> answer;
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> currInterval = {intervals[i][0], intervals[i][1]};
            while (i < intervals.size() &&
                   min(currInterval[1], intervals[i][1]) - max(currInterval[0], intervals[i][0]) >= 0) {
                currInterval = {min(currInterval[0], intervals[i][0]), max(currInterval[1], intervals[i][1])};
                i++;
            }
            i--;
            answer.push_back(currInterval);
        }
        
        return answer;
    }
};
