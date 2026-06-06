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

    void traverse(TreeNode* root, vector<pair<int, pair<int,int>>>& v, int level, int sides)
    {
        if(!root) return;


        v.push_back({root->val, {level, sides}});

        traverse(root->left, v, level+1, sides-1);
        traverse(root->right, v, level+1, sides+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<pair<int, pair<int,int>>> v;

        traverse(root, v, 0, 0);

        vector<vector<int>> ans;

        sort(v.begin(), v.end(),
            [](const pair<int, pair<int,int>>& p1,
            const pair<int, pair<int,int>>& p2)

        {
            if(p1.second.second != p2.second.second) return p1.second.second < p2.second.second;
            
            
            else if(p1.second.first != p2.second.first) return p1.second.first < p2.second.first;


            else return p1.first<p2.first;

            
        });

        vector<int> columns;
        int prev_col =INT_MIN;
        for(auto [val, pos] : v)
        {
            int row = pos.first;
            int col = pos.second;
            if(col!=prev_col)
            {
                if(!columns.empty()) ans.push_back(columns);
                columns.clear();
                prev_col= col;
            }
            columns.push_back(val);
        }
        if(!columns.empty()) ans.push_back(columns);

        return ans;
    }
};