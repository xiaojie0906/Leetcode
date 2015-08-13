class Solution {
public:
    bool isPalindrome(int x) {
        if(x <0)
            return false;
        if(0 ==x )
            return true;
        int rx = reverse(x);
        return rx == x;
    }
    int reverse(int x) {//x>0
        int t=0,answer=0,overflow;
        while(x != 0){
            t = x%10;
            x /= 10;
            overflow = answer*10+t;
            if((overflow -t)/10 != answer)
                return 0;
            else
                answer = overflow;
        }
        return answer;
        
    }
};