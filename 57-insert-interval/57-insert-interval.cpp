class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int size = intervals.size();
        vector< vector<int> > ans;
        for(int index = 0; index < intervals.size(); index ++ ){
            if(intervals[index][0] >= newInterval[0]){
                intervals.insert(intervals.begin() + index, newInterval);
                break;
            }
        }
        if(size == intervals.size()){
            intervals.push_back(newInterval);
        }
        
        vector<int> interval = intervals[0];
        
        
        for(int index = 0 ; index < intervals.size(); index ++ ){
            if(interval[1] >= intervals[index][0]){
                interval[1] = max(intervals[index][1], interval[1]);
            }else{
                ans.push_back(interval);
                interval = intervals[index];
            }
        }
        
        ans.push_back(interval);
        return ans;
    }
};