class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rowSize = triangle.size();
        int colSize = triangle[rowSize - 1].size();
        vector< vector<int> > dp(rowSize, vector<int>(colSize, 10000000));

        dp[0][0] = triangle[0][0];

        for(int i = 1 ; i < rowSize; i ++ ){
            for(int j = 0 ; j < i + 1; j ++ ){
                int left = dp[i-1][j] + triangle[i][j];
                int right = 10000000;
                if(j > 0 ) right = dp[i - 1][ j - 1] + triangle[i][j];
                dp[i][j] = min(left, right);
            }
            cout << endl;
        }

        int ans = 10000000;
        for(int i = 0; i  < colSize; i ++ ){
            ans = min(ans, dp[rowSize - 1][i]);
        }
        return ans;
	
    }
};