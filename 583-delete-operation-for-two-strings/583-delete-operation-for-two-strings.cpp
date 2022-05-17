class Solution {
public:
 int minDistance(string str, string ptr) {
    int strSize = str.size();
	int ptrSize = ptr.size();
	
     vector< int > prev(ptrSize + 1, 0);
	
	
	for(int index1 = 1; index1 <= strSize; index1 ++ ){
         vector< int > cur(ptrSize + 1, 0);
		for(int index2 = 1; index2 <= ptrSize; index2 ++ ){
			if(str[index1 - 1] == ptr[index2 - 1]){
				cur[index2] = 1 + prev[index2 - 1];
			}else{
				cur[index2] = max(prev[index2],
										cur[index2 - 1]);
			}
		}
        prev = cur;
	}
     
   
	int lcs = prev[ptrSize];
	int toDelete = strSize - lcs;
	int toAdd = ptrSize - lcs;
	return toAdd + toDelete;
	
    }
};