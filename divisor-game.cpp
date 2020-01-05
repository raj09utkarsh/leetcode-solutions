class Solution {
public:
    bool divisorGame(int N) {
        if(N == 1) return false;
        int dp[N+1] = {0};
        dp[1] = 0;
        dp[2] = 1;
        for(int i=3; i<=N; i++){
            for(int j=1; j<=sqrt(i); j++){
                if(i%j == 0){
                    if(dp[i-j] == 0){
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        return dp[N];
    }
};