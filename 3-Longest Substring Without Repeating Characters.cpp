class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int prepos[256];
       for(int i=0; i< 256; i++)
        prepos[i] = -1;
	    int pos = 0;
		int start = 0,end = 0,gmax = 0;
		for(size_t i =0; i < s.length(); i++){
				pos = prepos[s[i]];
			    prepos[s[i]] = i;
	
			if(pos < start){
				end = i;
				gmax = max(gmax,end-start+1);
			}
			else{
				start = pos+1;
				end = i;
			}
		}
		return gmax; 
    }
};