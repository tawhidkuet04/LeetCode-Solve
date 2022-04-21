class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        
        vector< vector<int> > ans;

        sort(intervals.begin(), intervals.end(), [](auto const first, auto const second){
            if(first[0] < second[0]){
                return true;
            }else if(first[0] == second[0]){
                return first[1] < second[1];
            }else{
                return false;
            }
        });
        
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