class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        priority_queue<int> pq;
        
        for(int i=0; i<hand.size(); i++)
        {
            pq.push(hand[i]);
        }

        while(!pq.empty())
        {
            
            vector<int> temp;
            int count =0;
            int curr =-1;

            while(!pq.empty() && count<groupSize)
            {

            int num = pq.top();

            pq.pop();

            while(!pq.empty() && pq.top()==num)
            {
                temp.push_back(pq.top());
                pq.pop();
            }

            if(curr==-1) {curr = num; count++;}

            else if(curr!=-1 && curr != num +1) return false;

            else {curr = num; count++;}

            }

            for(int x : temp) pq.push(x);

            if(pq.empty() && count != groupSize ) return false;

        }

        return true;
    }
};