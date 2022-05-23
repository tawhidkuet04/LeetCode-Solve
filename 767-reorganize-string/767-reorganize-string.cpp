class Solution {
public:
    
    bool isValid( map<char, int> & charMp){
        int cnt = 0;
        for(char ch = 'a'; ch <= 'z'; ch ++ ){
            int val = ch;
            // cout << ch << "val" << charMp[val] << endl;
            cnt += charMp[ch];
        }
        
        if(cnt > 0) return true;
        else return false;
    }
    
    bool canMake(string s){
        if(s.size() > 1){
            if (s[s.size() - 2 ] != s[s.size() - 1]) return true;
            else return false;
        }else{
            return true;
        }
    }

    string reorganizeString(string s) {
        
        unordered_map<char, int> mp;
        char mostFreq = '.';
        
        
        int totalCount = 0;
        for(char &ch : s){
            mp[ch] ++ ;
            if(mp[ch] > mp[mostFreq]){
                mostFreq = ch;
            }
        }
        
        for(char ch = 'a'; ch <= 'z'; ch ++){
            totalCount += mp[ch];
        }
        // totalCount -= mp[mostFreq];
         int limit =  totalCount/ 2;
        if( totalCount % 2 ){
            limit =  totalCount/ 2 + 1;
        }
        if((mp[mostFreq]) > limit ) return "";
        int index = 0;
        
        while(mp[mostFreq]){
            s[index] = mostFreq;
            index += 2;
            mp[mostFreq] --;
        }
        
        for(int charIndex = 0; charIndex < 26; charIndex ++){
            char currentChar = charIndex + 'a';
            
            while(mp[currentChar]){
                if(index >= s.size()){
                    index = 1;
                }
                s[index] = currentChar;
                mp[currentChar] -- ;
                index += 2;
            }
        }
        return s;
        
        
    }
    
    
};

// 2 2 2 2 2 

// ababcdcdefefa

// l o v

// lov

// 3 3 2
       // ccccabababababac
      
//     aaaaabbbcc

//     abacababa
//     abcabcabaa
    
//     abababcc
    
    
//     -a-
//      a-
//      a-
//     -b-
//     -b-
//     -b-
//     -c-
//     -c-
    // a a a a a
    
//      b a b a b a b
     
//     bababab
    
//     cbabababczzzz
    
//     z - 4
//     a - 4
//     b - 4
//     c - 1
    
//     czbabzbazbazazc
    
//     aaaabbbbccc
     
     
//      cbcabababac
     
//      ababacacbcb
       

// "vvvlo"
    
//     vlvov

