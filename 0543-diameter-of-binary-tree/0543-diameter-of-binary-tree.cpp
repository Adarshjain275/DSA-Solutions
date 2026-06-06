/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    int maxim(TreeNode* root, int& maxi)
    {
        if(!root) return 0;

        int lh = maxim(root->left, maxi);
        int rh = maxim(root->right, maxi);

        maxi = max(maxi, lh+rh);

        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxi =0;

        int m = maxim(root, maxi);

        return maxi;
    }
};