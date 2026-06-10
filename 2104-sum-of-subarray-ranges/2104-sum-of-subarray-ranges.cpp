class Solution {
public:

    long long subArrayRanges(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> prevSmall(n), nextSmall(n);
        vector<int> prevLarge(n), nextLarge(n);

        stack<int> st;

        // Previous Smaller
        while(!st.empty()) st.pop();

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            prevSmall[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Next Smaller
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            nextSmall[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Previous Greater
        while(!st.empty()) st.pop();

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            prevLarge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Next Greater
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            nextLarge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long minSum = 0;
        long long maxSum = 0;

        for(int i=0;i<n;i++)
        {
            long long leftMin = i - prevSmall[i];
            long long rightMin = nextSmall[i] - i;

            long long leftMax = i - prevLarge[i];
            long long rightMax = nextLarge[i] - i;

            minSum += 1LL * nums[i] * leftMin * rightMin;
            maxSum += 1LL * nums[i] * leftMax * rightMax;
        }

        return maxSum - minSum;
    }
};