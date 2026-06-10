class Solution {
    
    void getcombs(int k, int n,int index, vector<int>& demo, vector<vector<int>>& ans)
    {
         if(k == 0 && n == 0) {
            ans.push_back(demo);
            return;
        }
        if(index > 9 || n < 0 || k < 0) return;
        
        demo.push_back(index);
        getcombs(k-1, n-index, index+1, demo, ans);
        demo.pop_back();
        getcombs(k,n, index+1, demo, ans);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;

        vector<int> demo;
        getcombs(k, n,1, demo, ans);

        return ans;
    }
};