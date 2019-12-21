class Solution {
public:
    int fac(int n){
        int ans = 1;
        for(int i=2; i<=n; i++){
            ans = ans*i;
        }
        return ans;
    }
    string solve(string s, int n, int k, int i){
        // base case
        if(k == 0 || n == 1){
            return s;
        }
        
        // rec case
        int k1 = (k-1)/fac(n-1);
        swap(s[i], s[i+k1]);
        sort(s.begin() + i + 1, s.end());
        k1 = k1*fac(n-1);
        s = solve(s, n-1, k - k1, i+1);
        return s;
    }
    
    string getPermutation(int n, int k) {
        string s = "";
        for(int i=1; i<=n; i++){
            s += i + '0';
        }
        int i = 0;
        return solve(s, n, k, i);
    }
};