class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const auto box1, const auto box2){
            return box1[1] > box2[1];
        });
        
        // int truckSize = truckSize;
        int totalUnit = 0;
        
        for(int i = 0; i < boxTypes.size(); i++ ){
            if ((truckSize - boxTypes[i][0]) >= 0){
                totalUnit += boxTypes[i][0] * boxTypes[i][1];
            }else{
                totalUnit += truckSize * boxTypes[i][1];
                return totalUnit;
            }
            truckSize -=  boxTypes[i][0];
        }
        
        return totalUnit;
    }
};