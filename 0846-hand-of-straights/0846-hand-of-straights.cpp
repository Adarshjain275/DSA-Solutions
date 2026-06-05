class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if(n % groupSize != 0)
            return false;

        map<int,int> freq;

        for(int x : hand)
            freq[x]++;

        sort(hand.begin(), hand.end());

        for(int card : hand)
        {
            if(freq[card] == 0)
                continue;

            for(int next = card;
                next < card + groupSize;
                next++)
            {
                if(freq[next] == 0)
                    return false;

                freq[next]--;
            }
        }

        return true;
    }
};