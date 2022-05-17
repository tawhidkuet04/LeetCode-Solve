class Solution {
public:
 int minDistance(string str, string ptr) {
    int strSize = str.size();
	int ptrSize = ptr.size();
	vector< vector<int> > dp(strSize + 1, vector<int> (ptrSize + 1, 0));
	
	
	for(int index1 = 1; index1 <= strSize; index1 ++ ){
		for(int index2 = 1; index2 <= ptrSize; index2 ++ ){
			if(str[index1 - 1] == ptr[index2 - 1]){
				dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
			}else{
				dp[index1][index2] = max(dp[index1 - 1][index2],
										dp[index1][index2 - 1]);
			}
		}
	}
     
   
	int lcs = dp[strSize][ptrSize];
	int toDelete = strSize - lcs;
	int toAdd = ptrSize - lcs;
	return toAdd + toDelete;
	
    }
};