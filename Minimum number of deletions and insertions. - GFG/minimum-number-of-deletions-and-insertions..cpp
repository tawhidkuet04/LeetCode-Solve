// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str, string ptr) 
	{ 
	    int strSize = str.size();
	    int ptrSize = ptr.size();
	vector< vector<int> > dp(strSize + 10, vector<int> (ptrSize + 10, 0));
	
	
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
// 	cout << lcs << endl;
    int ans = toAdd + toDelete;
	return  ans;
	
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends