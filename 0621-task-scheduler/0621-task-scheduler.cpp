class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;

        for(char task : tasks)
            freq[task]++;

        priority_queue<int> pq;

        for(auto &it : freq)
            pq.push(it.second);

        int time = 0;

        while(!pq.empty())
        {
            vector<int> temp;

            int cycle = n + 1;

            while(cycle > 0 && !pq.empty())
            {
                int cnt = pq.top();
                pq.pop();

                cnt--;

                if(cnt > 0)
                    temp.push_back(cnt);

                time++;
                cycle--;
            }

            for(int cnt : temp)
                pq.push(cnt);

            // If tasks remain, we must account for idle slots
            if(!pq.empty())
                time += cycle;
        }

        return time;
    }
};