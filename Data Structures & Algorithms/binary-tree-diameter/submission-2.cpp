class Solution {
public:
    int ans = 0;
    int solve(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);

        int d=left+ right;
        ans=max(ans,d);

        int h=max(left,right);
        h++;

        return h;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};