class Solution {
public:
    struct trip{
        int passenger;
        int distance;
        bool isStart;
        
        trip(int passenger, int distance, bool isStart){
            this->passenger = passenger;
            this->distance = distance;
            this->isStart = isStart;
        }
    };
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
         vector< trip > arr ;
        
        for(int index = 0; index < trips.size(); index ++ ){
            int from = trips[index][1];
            int to = trips[index][2];
            int passenger = trips[index][0];
            
            arr.push_back(trip(passenger, from, true));
            arr.push_back(trip(passenger, to, false));
        }
        
        sort(arr.begin(), arr.end(), [] (const trip &first, const trip &second) -> bool{
            if(first.distance < second.distance) return true;
            else if(first.distance ==  second.distance){
                return first.isStart < second.isStart;
            }else {
                return false;
            }
        }) ;
        
        int total = 0 ;
        
        for(int index = 0; index < arr.size(); index ++ ){
           
            auto curTrip = arr[index];
             // cout << curTrip.passenger << " " << curTrip.distance << endl;
             
            if(curTrip.isStart){
                total +=  curTrip.passenger;
            }else{
                 total -= curTrip.passenger;
            }
            // cout << total << endl;
            if(total > capacity ) return false;
            
        }
        
        return true;
    }
    
};