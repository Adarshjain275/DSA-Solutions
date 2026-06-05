class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        for(int i :nums) mp[i]++;

        priority_queue<pair<int,int>> pq;

        for(auto it : mp)
        {
            pq.push({it.second, it.first});
        }

        vector<int> ans;

        for(int i=0; i<k; i++)
        {
            auto it = pq.top();
            ans.push_back(it.second);
            pq.pop();
        }

        return ans;
    }
};