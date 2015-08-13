class Solution {
public:
    void preOP(string &s){
        string ::size_type start,i;
        for(i =0; i< s.length(); i++){
            if(s[i] !=' ')
                break;
        }
        start = i;
        if(i<s.length())
            s = s.substr(start);
    }
    int myAtoi(string str) {
        preOP(str);//discard whitespace
        if(str.empty())
            return 0;
        int positive = 1,i=0;
        if(str[i]=='-'){
            positive = 0;
            i++;
        }
        else if(str[i] == '+')
            i++;
        long long val = 0;
        int  x;
        for(;i<str.length()&&str[i]>='0' && str[i]<='9'; i++){
            x = str[i] - '0';
            val = 10*val + x;
            if(positive && val > INT_MAX)
                return INT_MAX;
            if(!positive && val-1 > INT_MAX)
                return INT_MIN;
        }
        if(!positive)
            return 0-val;
        return val;
    }
};