class Solution {
public:
//DP
bool isMatch(string s, string p) {
	if(s.empty() && p.empty())
		return true;
	if(p.empty())
		return false;
/*t[i][j] 表示s[0...i-1] 与 p[0...j-1]是否匹配
*t[i][j+1] 分情况讨论：1,p[j] 为字母且p[j]==s[i-1]或o[j]='.'，t[i][j+1] = t[i][j]
* 2,p[j] 为字母且p[j] !=s[i-1],t[i][j+1] =false;
*3,p[j]='*',若p[j-1]为'.'，则搜索t[0...i][j-1],有true则为true，
*           若p[j-1]为字母，则对s[0...i-1]后缀中字母等于p[j]的串，搜索t[k][j-1],有true为true
*/
	vector<vector<bool> > t(s.length()+1,vector<bool>(p.length()+1,false));
	t[0][0] = true;//null == null

	for(int i=0; i< p.length() ; i++){//s=null,
		if(p[i] == '*')
			t[0][i+1] = t[0][i-1];
	}

	for(int i=0; i<s.length(); i++)
		for(int j=0; j< p.length(); j++){
			if(s[i] == p[j] || p[j] == '.')
				t[i+1][j+1] = t[i][j];
			else if(p[j] != '*')
				t[i+1][j+1]  = false;
			else {//p[j]=='*'
				if(p[j-1] == '.'){
					for(int k=i+1;k>=0; k--)
						if(t[k][j-1]){
							t[i+1][j+1] = true;
							break;
						}
				}
				else{
					t[i+1][j+1] = t[i+1][j-1];//p[j-1]p[j-1]匹配s末尾中0个字符
					for(int k=i;k>=0 && s[k] == p[j-1]; k--)//p[j-1]p[j-1]匹配s中1个或多个字符
						if(t[k][j-1]){
							t[i+1][j+1] = true;
							break;
						}
				}
			}
		}
		
		return t[s.length()][p.length()];
}

};