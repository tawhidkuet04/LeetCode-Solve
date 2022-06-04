struct Visitor{
   string username;
   int  timestamp;
   string website;
    
    Visitor(string username, int timestamp, string website){
        this->username = username;
        this->timestamp = timestamp;
        this->website = website;
    }
    
    bool isSameUser(Visitor &firstVisitor){
        return this->username == firstVisitor.username;
    }
    
};


class Solution {
public:
    


    
               
    void splitHash(string &hash,  vector<string> &ans){
        stringstream ss(hash);
        string token;
        
        while(getline(ss, token, '#')){
            ans.push_back(token);
        }
    }
    
    
    void createPattern( unordered_map<string, map<int, string> >  &mp, map<string, int > &patternCountMp, int &maxCount){
        
        for(auto userPattern: mp){
            auto userPatternList = userPattern.second;
            unordered_set<string> st;
            for(auto it = userPatternList.begin(); it != userPatternList.end(); it ++ ){
                for(auto it1 = next(it); it1 != userPatternList.end(); it1 ++){
                    for(auto it2 = next(it1); it2 != userPatternList.end(); it2 ++){
                        st.insert(it->second + "#" + it1->second + "#" + it2->second);
                    }
                }
            }
            
            for(auto &val: st){
                maxCount = max(maxCount, ++patternCountMp[val]);
            }
            
            
            
        }
        
    }
    
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        
        unordered_map<string, map<int, string> > mp;
        
        int sz = username.size();
        
        for(int index = 0; index < sz; index ++ ){
            mp[username[index]][timestamp[index]] = website[index];
        }
        
        
        map<string, int > patternCountMp;
        int maxCount = 0;
        
        createPattern(mp, patternCountMp, maxCount);
        
        string maxHash = "";
        
        for(auto &keyVal: patternCountMp){
            // cout << keyVal.first << " "<< keyVal.second << endl;
            // if(maxHash.size() == 0){
            //     maxHash =  keyVal.first;
            // }
            // else if(keyVal.second == maxCount){
            //     // maxHash = min(maxHash, keyVal.first);
            // }
            
            if(keyVal.second == maxCount){
                maxHash = keyVal.first;
                break;
            }
        }
        
        vector<string> ans;
        
        splitHash(maxHash, ans);
        
        
        return ans;
        
        
        
    }
};

// ["joe","home",1],
// ["joe","about",2],
// ["joe","career",3],

// ["james","home",4],
// ["james","cart",5],
// ["james","maps",6],
// ["james","home",7],

// ["mary","home",8],
// ["mary","about",9]
// ["mary","career",10].