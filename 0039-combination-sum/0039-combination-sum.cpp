class Solution {
public:
    void count(vector<int>& candidates, int target, vector<int>& demo, int index, vector<vector<int>>& ans) {
        if (target == 0) {  
            ans.push_back(demo);
            return;
        }
        if (index >= candidates.size() || target < 0) return; 

        count(candidates, target, demo, index + 1, ans);

        demo.push_back(candidates[index]);
        count(candidates, target - candidates[index], demo, index, ans);
        demo.pop_back(); 
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> demo;
        count(candidates, target, demo, 0, ans);
        return ans;
    }
};