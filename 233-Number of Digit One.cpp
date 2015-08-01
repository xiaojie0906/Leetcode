class Solution {
public:
//9 一个1,99 20个1，999 300个1，如五位数abcde,先计算9999有多少个1，如a是1，加上（bcde+1）个1，如a>1，乘以a,则加上10000，递归求bcde有多少个1，
    int countDigitOne(int n) {
        int count = 0;
        int m = n,base = 1;
        if(m<10)
            if(m<1)
                return 0;
            else
                return 1;
        while(m/=10)
            base*=10;
        m = n/base;//首位数字
        int basetmp = base;
        int dec = 1;
        while(basetmp/=10){
            count =count *10 + dec;
            dec *= 10;
        }
        if(m == 1)
            count += (n%base) + 1;
        else
            count = count * m + base;
        return count + countDigitOne(n%(base));
    }
};