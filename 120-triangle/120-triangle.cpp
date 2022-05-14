class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rowSize = triangle.size();
        int colSize = triangle[rowSize - 1].size();
        vector< int > dp(rowSize, 10000000);

        dp[0] = triangle[0][0];

        for(int i = 1 ; i < rowSize; i ++ ){
            vector< int > tempDp(rowSize, 10000000);
            for(int j = 0 ; j < i + 1; j ++ ){
                int left = dp[j] + triangle[i][j];
                int right = 10000000;
                if(j > 0 ) right = dp[ j - 1] + triangle[i][j];
                tempDp[j] = min(left, right);
            }
            dp = tempDp;
        }

        int ans = 10000000;
        for(int i = 0; i  < colSize; i ++ ){
            ans = min(ans, dp[i]);
        }
        return ans;
	
    }
};

// 1
// 1 2
// 1 2 3