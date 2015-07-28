class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        if(nums.empty())
            return result;
       
       result.resize(nums.size(),0);
       result[0] = 1;
       for(int i =1; i<nums.size(); i++)
           result[i] = result[i-1] * nums[i-1];
       for(int i= nums.size() -1 ; i>0 ;i--){
           result[i] = result[0] * result[i];
           result[0] = result[0] * nums[i];
       }
       return result;
    }
};