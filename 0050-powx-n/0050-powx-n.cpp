class Solution {
public:
    double myPow(double x, long long n) {

        if(n==0) return 1;

        if(n<0)
        {
            n = -n;
            x=1/x;
        }
        
        double h =myPow(x, n/2);
        if(n%2 == 1) { return h*h*x;}
        return h*h;
       
    }
};