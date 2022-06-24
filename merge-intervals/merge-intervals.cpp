  struct Meeting{
        int time;
        bool isStarted;
        
        Meeting(int time, bool isStarted){
            this->time = time;
            this->isStarted = isStarted;
        }
    };
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector< Meeting > meetings;
        int roomsNeeded = 0;
        for(auto &interval : intervals){
            Meeting startMeeting = Meeting(interval[0], true);
            Meeting endMeeting = Meeting(interval[1], false);
            meetings.push_back(startMeeting);
            meetings.push_back(endMeeting);
        }
        
        sort(meetings.begin(), meetings.end(), [](auto const &first, auto const &second){
            if(first.time < second.time){
                return true;
            }else if(first.time == second.time){
                 return first.isStarted > second.isStarted;
            }else return false;
        });
        
        int rooms = 0;
        int size = meetings.size();
        vector< vector<int> > ans;
        int start = 0;
        for(int index = 0; index < size; index ++){
            if(meetings[index].isStarted){
                rooms ++;
                if(rooms == 1){
                    start = meetings[index].time;
                }
                roomsNeeded = max(roomsNeeded, rooms);
            }else{
                rooms --;
                if(rooms == 0){
                    ans.push_back({start,  meetings[index].time});
                }
            }
        }
        
        return ans;
    }
};