// O(n) solution

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            dp[i] = 1 + dp[(i)&(i-1)];
        }
        return dp;
    }
};