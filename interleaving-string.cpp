class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), o = s3.size();
        if(n + m != o){
            return false;
        }
           
        int dp[n+1][m+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for(int i=1; i<=n; i++){
            if(s1[i-1] == s3[i-1]){
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int j=1; j<=m; j++){
            if(s2[j-1] == s3[j-1]){
                dp[0][j] = dp[0][j-1];
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s3[i+j-1] && dp[i-1][j]){
                    dp[i][j] = 1;
                }
                else if(s2[j-1] == s3[i+j-1] && dp[i][j-1]){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[n][m];
    }
};