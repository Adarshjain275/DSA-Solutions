class Fenwick {
public:
    vector<int> bit;
    int n;

    Fenwick(int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val)
    {
        while(idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx)
    {
        int sum = 0;

        while(idx > 0)
        {
            sum += bit[idx];
            idx -= idx & -idx;
        }

        return sum;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        vector<int> temp = nums;

        sort(temp.begin(), temp.end());

        unordered_map<int,int> rank;

        int r = 1;

        for(int x : temp)
        {
            if(!rank.count(x))
                rank[x] = r++;
        }

        Fenwick ft(r);

        vector<int> ans(n);

        for(int i = n-1; i >= 0; i--)
        {
            int pos = rank[nums[i]];

            ans[i] = ft.query(pos - 1);

            ft.update(pos, 1);
        }

        return ans;
    }
};