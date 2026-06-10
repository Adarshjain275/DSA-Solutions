class Solution {

    void solve(int index, vector<vector<int>>& ans, vector<int> temp, vector<int>& nums)
    {

        ans.push_back(temp);
            
        for(int i =index; i<nums.size(); i++)
        {
            if(i>index && nums[i]==nums[i-1]) continue;

            temp.push_back(nums[i]);
            solve(i+1, ans, temp, nums);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(0, ans, temp, nums);

        return ans;
    }
};