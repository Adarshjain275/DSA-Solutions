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

    void traverse(TreeNode* root, queue<TreeNode*>& q)
    {
        if(!root) return;

        q.push(root);

        traverse(root->left, q);
        traverse(root->right, q);
    }
public:
    void flatten(TreeNode* root) {
        
        queue<TreeNode*> q;
        if(!root) return;
        traverse(root, q);

        TreeNode* a = q.front();
        q.pop();
        a->left = NULL;
        while(!q.empty())
        {
            a->right = q.front();
            a->left = NULL;
            q.pop();
            a = a->right;
        }

        if(a->right) a->right = NULL;
    }
};