class Solution {
    void genpos(vector<string> &ans, int n, string s)
    {
        if(s.size()==n) 
        {
            ans.push_back(s);
            return;
        }

        genpos(ans, n, s + '1');
        

        if(s.empty()|| s.back() != '0')
        {
            genpos(ans, n, s+'0');
        }
    }   
public:
    vector<string> validStrings(int n) {
        
        vector<string> ans;

        string s ="";
        genpos(ans, n, s);
        return ans;

    }
};