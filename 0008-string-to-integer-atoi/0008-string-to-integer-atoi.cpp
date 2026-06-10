class Solution {
public:

    long long build(string& s, int i, long long num, int sign)
    {
        if(i >= s.size() || !isdigit(s[i]))
            return num;

        int digit = s[i] - '0';

        if(sign == 1)
        {
            if(num > INT_MAX/10 ||
               (num == INT_MAX/10 && digit > 7))
                return INT_MAX;
        }
        else
        {
            if(num > INT_MAX/10 ||
               (num == INT_MAX/10 && digit > 8))
                return (long long)INT_MAX + 1;
        }

        return build(s, i+1, num*10 + digit, sign);
    }

    int myAtoi(string s)
    {
        int i = 0;

        while(i < s.size() && s[i] == ' ')
            i++;

        int sign = 1;

        if(i < s.size() && (s[i] == '+' || s[i] == '-'))
        {
            if(s[i] == '-')
                sign = -1;

            i++;
        }

        long long num = build(s, i, 0, sign);

        if(sign == -1)
        {
            if(num == (long long)INT_MAX + 1)
                return INT_MIN;

            return -num;
        }

        return num;
    }
};