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
public:
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*, long long>> q;
        q.push({root,1});
        long long maxi =1;


        while(!q.empty())
        {

            int size = q.size();

            long long minindex = q.front().second;

            long long left = minindex ;
            long long right = minindex;

            for(int i=0; i< size; i++)
            {

                long long index = q.front().second;
                TreeNode* curr = q.front().first;

                index -= minindex;

                if(i==0) left = index;
                if(i==size-1) right = index;

                if(curr->left) q.push({curr->left, index*2});
                if(curr->right) q.push({curr->right, index*2 +1});

                q.pop();
            }

            maxi = max(maxi, right -left +1);
        }
        return maxi;
    }
};