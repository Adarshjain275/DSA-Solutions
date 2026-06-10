class Solution {
    void genpos(vector<string> &ans, int n, string &s)
    {
        if(s.size()==n) 
        {
            ans.push_back(s);
            return;
        }

        s.push_back('1');
        genpos(ans, n, s);
        s.pop_back();

        if(s.empty()|| s.back() != '0')
        {
            s.push_back('0');
            genpos(ans, n, s);
            s.pop_back();
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