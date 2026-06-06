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
    void relateparent(TreeNode* root, map<TreeNode*, TreeNode*>& mp)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            auto parent = q.front();
            q.pop();

            if(parent->left) {q.push(parent->left); mp[parent->left]=parent;}
            if(parent->right) {q.push(parent->right); mp[parent->right]=parent;}
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        map<TreeNode*, TreeNode*> mp;

        relateparent(root, mp);

        int count =0;
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, bool> vis;
        vis[target] =true;
        while(!q.empty())
        {
            if(count++ == k) break;
            int size = q.size();

            for(int i=0; i<size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right])
                {
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(mp[curr] && !vis[mp[curr]])
                {
                    q.push(mp[curr]);
                    vis[mp[curr]]=true;
                }
            }
        }

        vector<int> ans;

        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};