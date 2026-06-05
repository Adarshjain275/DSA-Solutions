class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<int> s = arr;
        sort(s.begin(), s.end());

        unordered_map<int,int> mp;

        int rank =1;
        for(int i =0; i<arr.size(); i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]] = rank++;
            }
        }

        for(int i=0; i< arr.size(); i++)
        {
            s[i] = mp[arr[i]];
        }

        return s;
    }
};