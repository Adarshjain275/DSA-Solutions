class Solution {

    long long pow(long long b, long long e)
    {
        long long res =1;
        while(e>0)
        {
            if(e%2==1) {res = (res*b)%1000000007; };

            b = (b*b)%1000000007;
            e = e/2;
        }
        return res;
    }
public:
    int countGoodNumbers(long long n) {
        long long p_4 =1;
        long long p_5 =1;
        p_4 = pow(4,(n/2));
        p_5 = pow(5,(n-n/2));


        int i = (p_4*p_5)%1000000007;
        return i;
    }
};