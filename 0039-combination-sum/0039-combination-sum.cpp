class Solution {
public:
    void solve(int index, int target, vector<vector<int>>& ans, vector<int> temp, vector<int>& candidates)
    {
    if(target == 0)
    {
        ans.push_back(temp);
        return;
    }

    for(int i=index; i<candidates.size(); i++)
    {
        if(candidates[i] > target) break;

        temp.push_back(candidates[i]);

        solve(i, target-candidates[i], ans, temp, candidates);   // i, not i+1

        temp.pop_back();
    }
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> demo;

        sort(candidates.begin(), candidates.end());
        solve(0, target, ans, demo, candidates);
        return ans;
    }
};