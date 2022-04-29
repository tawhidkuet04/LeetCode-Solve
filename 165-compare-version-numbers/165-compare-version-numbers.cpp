class Solution {
public:
    int compareVersion(string version1, string version2) {
        int version1Index = 0 , version2Index = 0 , 
        version1Size = version1.size(), version2Size = version2.size();
        
        
        int version1Num = 0 , version2Num = 0 ;
        
        while(version1Index < version1Size || version2Index < version2Size){
            version1Num = 0;
            version2Num = 0;
            while( version1Index < version1Size  && version1[version1Index] != '.'){
                version1Num = (version1Num * 10) + (version1[version1Index] - '0');
                version1Index ++;
            }
            
            while(version2Index < version2Size && version2[version2Index] != '.'){
                version2Num = (version2Num * 10) + (version2[version2Index] - '0');
                version2Index ++;
            }
            
            if(version1Num < version2Num){
                return -1;
            }else if(version1Num > version2Num){
                return 1;
            }
            version1Index ++;
            version2Index ++;
        
        }
       
        return 0;
    }
};