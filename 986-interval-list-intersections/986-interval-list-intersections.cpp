class Solution {
public:
    
    vector<int> getOverlapedSegment(vector<int> first, vector<int> second){
        if(first[0] > second[0]){
            swap(first, second);
        }
        vector<int>overLapped;
        if(first[1] >= second[0]){
            int start = min(first[1], second[0]);
            int end = min(first[1], second[1]);
            overLapped.insert( overLapped.begin(), {start, end});
            return overLapped;
        }else{
            return overLapped;
        }
    }
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector< vector<int> > ans;
        
        int firstListLength = firstList.size();
        int secondListLength = secondList.size();
        
        if(firstListLength == 0 ||
          secondListLength == 0){
            return ans;
        }
        
        
        int firstListIndex = 0, secondListIndex = 0;
        
        
        while( firstListIndex < firstListLength && 
              secondListIndex < secondListLength){
            
            auto overLapped = getOverlapedSegment(firstList[firstListIndex],
                                                 secondList[secondListIndex]);
            if(overLapped.size() != 0){
                ans.push_back(overLapped);
            }
            
            if(firstList[firstListIndex][1] > secondList[secondListIndex][1]){
                secondListIndex ++ ;
            }else{
                firstListIndex ++;
            }
        }
        
        return ans;
        
    }
};