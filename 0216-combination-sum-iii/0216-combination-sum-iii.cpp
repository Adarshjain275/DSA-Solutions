class Solution {
public:

    void solve(int start,
               int k,
               int target,
               vector<int>& temp,
               vector<vector<int>>& ans)
    {
        if(k == 0 && target == 0)
        {
            ans.push_back(temp);
            return;
        }

        if(k == 0 || target < 0)
            return;

        for(int i=start; i<=9; i++)
        {
            temp.push_back(i);

            solve(i+1, k-1, target-i, temp, ans);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(1, k, n, temp, ans);

        return ans;
    }
};