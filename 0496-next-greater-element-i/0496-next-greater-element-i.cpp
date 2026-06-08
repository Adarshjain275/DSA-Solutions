class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        map <int,int> mp;

        for(int n :nums2)
        {
            while(!s.empty() && s.top()<n)
            {
                mp[s.top()] =n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for(int n: nums1)
        {
            ans.push_back ( (mp.find(n) != mp.end())? mp[n] : -1);
        }
        return ans;
    }
};