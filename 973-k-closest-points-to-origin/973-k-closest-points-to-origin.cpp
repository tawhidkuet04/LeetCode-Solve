class Solution {
public:
    
    // 5 6 23 3 6 1 10
    
    int getDistance(vector<int> &point){
        return point[0] * point[0] + point[1] * point[1];
    }
    
    int findPivot(int lo, int hi, vector<vector<int>>& points){
        int pivotIndex = lo + rand() % (hi - lo + 1);
       
        
        swap(points[hi], points[pivotIndex]);
        
        int targetDistance = getDistance(points[hi]);
        
        pivotIndex = lo;
        
        for(int index = lo; index < hi; index ++ ){
            if(getDistance(points[index]) <= targetDistance){
                swap(points[index], points[pivotIndex ++ ]);
            }
        }
        
        swap(points[pivotIndex], points[hi]);
       
        return pivotIndex;
    }
    
    void quickSelect(int lo, int hi, vector<vector<int>>& points, int k){
         if(lo < hi){
             int pivot = findPivot(lo, hi, points);
            cout << pivot << endl;
             if( pivot == k){
                 return ;
             }else if(pivot < k){
                 quickSelect(pivot + 1, hi, points, k);
             }else{
                  quickSelect(lo, pivot - 1, points, k);
             }
         }
        
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         vector<vector<int>> ans;
        
         quickSelect(0, points.size() - 1, points, k);
        
        
        for(int index = 0; index < k; index ++ ){
            ans.push_back(points[index]);
        }
        
        return ans;
    }
};