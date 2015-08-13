class Solution {
public:
    int reverse(int x) {
        int t=0,answer=0,overflow;
        bool  is_negative = false;
        if(x < 0) {
            is_negative = true;
            x = 0-x;
        }
        else if(0 ==x)
            return 0;            
        while(x != 0){
            t = x%10;
            x /= 10;
            overflow = answer*10+t;
            if((overflow -t)/10 != answer)
                return 0;
            else
                answer = overflow;
        }
        
        if(is_negative)
            return 0-answer;
        else 
            return answer;
    }
};