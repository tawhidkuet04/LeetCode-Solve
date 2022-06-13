class Solution {
public:
    string convert(string s, int numRows) {
        
        
        if(numRows == 1) return s;
        
        unordered_map<int, string> mp;
        
        int chunkOne = numRows, chunkTwo = numRows - 2;
        
        int index = 0, sz = s.size();
        
        int mapIndex = 0, count = 0;
        
        bool flag = true;
        
        while(index < sz){
            if(flag){
                mp[mapIndex ++ ] += s[index ++ ];
                chunkOne -- ;
                if(chunkOne == 0){
                    flag = false;
                    chunkOne = numRows;
                    mapIndex = 0;
                }
            }else{
             //   cout<< " sdsd" << " " << s[index ] <<  endl;
                
            
                if(chunkTwo == 0){
                    flag = true;
                    chunkTwo = numRows - 2;
                    count += numRows - 2;
                    continue;
                }
                
                
                mp[numRows - 1 - (index - count) % numRows] += s[index ++ ];
                chunkTwo -- ;
                
                
            } 
            
            
        }
        
        string ans = "";
    
        for(int index = 0; index <numRows; index ++ ){
            ans += mp[index];
        }
        
        return ans;
        
    }
};

// A          I
 
// B       H
 
// C     G

// D   F

// E


// 0 1 2 3 4 5 6 7 8
// A B C D E F G H I 

// 13 14 15
    