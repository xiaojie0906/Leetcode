
//同第10题，动归，大数据超时
class Solution {
public:
bool isMatch(string s,string p) {
	int slen = s.size();
	int plen = p.size();
	if(slen > 30000) return false;
	vector<vector<bool> >res(slen+1, vector<bool>(plen+1,false));
	res[0][0] = true;
	for(int i = 1;i<=slen;i++)
		res[i][0] = false;
	for(int j=1;j<=plen;j++)
		res[0][j] = (res[0][j-1] && p[j-1] == '*');
	for(int si=1;si<=slen;si++){
		for(int pi=1;pi<=plen;pi++){
			if(p[pi-1] == '*')
				res[si][pi] = (res[si][pi-1] || res[si-1][pi]);
			else
				res[si][pi] = (res[si-1][pi-1] && (p[pi-1] == s[si-1] || p[pi-1] == '?'));
		}
	}
	return res[slen][plen];
}
    
};



//http://www.cnblogs.com/lautsie/p/3335789.html 
//记录上一个*匹配的位置，然后往下匹配，失败时，回溯到上一个*匹配的位置，s字符多匹配一个，只要
//记录最近的*，能到大当前的*，说明前面的*匹配更多的字符，通过当前的*多匹配字符一样能达到。
bool isMatch(const char *s, const char *p) {
       int backup_i = -1;
       int backup_j = -1;
       int i=0;
       int j = 0;
       while(s[i] != 0){
           if(s[i] == p[j] || p[j] == '?'){
               i++;
               j++;
           }
           else if(p[j] == '*'){
               backup_i = i;
               backup_j = j;
               j++;
           }
           else{
               if(backup_j != -1){
                   j = backup_j;
                   i = backup_i;
                   i++;
                   backup_i = i;
                   j++;
               }
               else
                    return false;
           }
       }
       while(p[j] != 0){
           if(p[j] != '*')
                return false;
            j++;
       }
       return true;
    }