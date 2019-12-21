class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        if(v.size() == 0 || v[0].size() == 0){
            return 0;
        }
        else if(v[0][0] == 1){
            return 0;
        }
        
        int n = v.size(), m = v[0].size();
        
        if((v[0][0] == -1) || (v[n-1][m-1] == -1)){
            return 0;
        }
        
        long long dp[n][m];
        dp[0][0] = 1;
        for(int i=1; i<n; i++){
            if(v[i][0] != 1){
                dp[i][0] = dp[i-1][0];
            }
            else{
                dp[i][0] = 0;
            }
        }
        for(int j=1; j<m; j++){
            if(v[0][j] != 1){
                dp[0][j] = dp[0][j-1];
            }
            else{
                dp[0][j] = 0;
            }
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                dp[i][j] = 0;
                if(v[i][j] != 1){
                    if(v[i-1][j] != 1)
                    {
                        dp[i][j] += dp[i-1][j];
                    }
                    if(v[i][j-1] != 1)
                    {
                        dp[i][j] += dp[i][j-1];
                    }
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};