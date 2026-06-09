class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int i=0; i<asteroids.size(); i++)
        {
            while(!ans.empty() && asteroids[i]<0 && ans[ans.size()-1]>0 && (-(asteroids[i]) >ans[ans.size()-1] ))
            {
                ans.pop_back();
            }
            if(!ans.empty() &&asteroids[i]<0 && ans[ans.size()-1]>0 && (-(asteroids[i]) < ans[ans.size()-1])) continue;
            if(!ans.empty() &&asteroids[i]<0 && ans[ans.size()-1]>0 && (-(asteroids[i]) == ans[ans.size()-1])) 
            { ans.pop_back(); continue;}

            ans.push_back(asteroids[i]);
        }
        return ans;
    }
};