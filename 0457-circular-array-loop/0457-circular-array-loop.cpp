class Solution {

public:

        int nextIndex(vector<int>& nums, int curr)
        {
            int n = nums.size();

            return ((curr + nums[curr]) % n + n) % n;
        }

        bool detect(vector<int>& nums, int start)
        {
            bool dir = nums[start] > 0;

            int slow = start;
            int fast = start;

            while(true)
            {
                if(nums[fast]==0 || nums[slow]==0) return false;
                int nextSlow = nextIndex(nums, slow);

                if((nums[slow] > 0) != dir || (nums[nextSlow] > 0) != dir) return false;

                int nextFast = nextIndex(nums, fast);

                if((nums[fast] > 0) != dir || (nums[nextFast] > 0) != dir) return false;

                nextFast = nextIndex(nums, nextFast);

                if((nums[nextFast] > 0) != dir) return false;
                
                slow = nextSlow;
                fast = nextFast;

                if(slow == fast)
                {
                    if(slow == nextIndex(nums, slow)) return false;   // self-loop

                    return true;
                }
            }
        }

    bool circularArrayLoop(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++)
        {
            if(detect(nums, i)) return true;
            nums[i] = 0;
        }

        return false;
    }
};