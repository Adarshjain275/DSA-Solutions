class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int a = arr.size();
        stack<int> n;
        stack<int> p;
        vector<int> l(arr.size());
        vector<int> r(arr.size());

        //for next less:
        for(int i =0; i< a; i++)
        {
            while(!n.empty() && arr[i]<arr[n.top()])
            {
                r[n.top()] = i-n.top();
                n.pop();
            }
            n.push(i);
        }
        while(!n.empty()) {r[n.top()]=a-n.top(); n.pop();}

        //for previous less:
        for(int j=0; j<a;j++)
        {
            while(!p.empty() && arr[p.top()]> arr[j])
            {
                p.pop();
            }
            l[j] = (p.empty())? j+ 1 : j-p.top();

            p.push(j);
        }

            long long ans =0;
            int mod = 1e9 +7;
        for(int k=0; k<arr.size(); k++)
        {
            ans =(ans +(1LL*arr[k]*l[k]*r[k])%mod)%mod;
        }
        return ans;
    }
};