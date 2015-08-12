
/*   A         G        N
*    B lgap F  H      M
*    C   E rgapI   L
*    D         K
*/



class Solution {
public:
    string convert(string s, int nRows) {
       string zigzag = "";
       if(s.length() <= nRows || 1== nRows)
              return s;
        int row =0,lastindex=0,j,lgap,rgap;
        int interval = 2*(nRows -1);
        for(row=0;row<nRows;row++){//按行从字符串中取出适当位置的字母
            lgap = 2*(nRows-1-row);//计算第row行字母与左边字母的距离
            rgap = 2*row;//计算第row行字母与右边字母的距离
            lastindex = row;//第row行开头字母的索引
            zigzag.append(s,row,1);
            for(j=0;;j++){
                if(j%2==0){//lgap,与上一个字母的距离是lgap
                    if(0 != lgap){
                        if(lastindex+lgap >= s.length())
                            break;
                        else{
                            zigzag.append(s,lastindex+lgap,1);
                            lastindex +=lgap;
                        }
                    }
                }
                else//,与上一个字母的距离是rgap
                {
                    if(0 != rgap){
                        if(lastindex+rgap >= s.length())
                            break;
                        else{
                            zigzag.append(s,lastindex+rgap,1);
                            lastindex +=rgap;
                        }
                    }
                }
            }
        }
        return zigzag;
    }
};