/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    long long solve(TreeNode* root, long long &ans){
        // base case
        if(root == NULL){
            return 0;
        }
        
        // rec case
        
        long long lmax = solve(root->left, ans);
        long long rmax = solve(root->right, ans);
        
        long long val1 = max(root->val + lmax, root->val + rmax);
        val1 = max(val1, root->val + lmax + rmax);
        val1 = max((long long)root->val, val1);
        
        ans = max(ans, val1);
        
        return max((long long)root->val, root->val + max(lmax, rmax));
    }
    int maxPathSum(TreeNode* root) {
        long long ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};