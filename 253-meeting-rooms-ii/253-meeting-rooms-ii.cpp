class Solution {
public:
    struct Meeting{
        int time;
        bool isStarted;
        
        Meeting(int time, bool isStarted){
            this->time = time;
            this->isStarted = isStarted;
        }
    };
    
    int minMeetingRooms(vector<vector<int>>& intervals) {

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
                if(first.isStarted){
                    return false;
                }else
                    return true;
            }else return false;
        });
        
        int rooms = 0;
        int size = meetings.size();
        
        for(int index = 0; index < size; index ++){
            if(meetings[index].isStarted){
                rooms ++;
                roomsNeeded = max(roomsNeeded, rooms);
            }else{
                rooms --;
            }
        }
        
        return roomsNeeded;
    }
};