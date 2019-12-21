class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > mat(n, vector<int> (n, 0));
        
        int cnt = 1;
        int u = 0, d = n-1, l = 0, r = n-1;
        
        while(cnt != n*n + 1)
        {
            // left to right
            for(int j=l; j<=r; j++){
                mat[u][j] = cnt;
                cnt++;
            }
            u++;

            // top to bottom
            for(int i=u; i<=d; i++){
                mat[i][r] = cnt;
                cnt++;
            }
            r--;

            // right to left
            for(int j=r; j>=l; j--){
                mat[d][j] = cnt;
                cnt++;
            }
            d--;

            // bottom to top
            for(int i=d; i>=u; i--){
                mat[i][l] = cnt;
                cnt++;
            }
            l++;
        }
        
        return mat;
    }
};