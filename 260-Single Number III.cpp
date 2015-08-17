class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret;
        if(nums.empty())
            return ret;
        int x = 0;
        for(size_t i =0; i< nums.size(); i++)//x为两个出现一次的数的异或
            x ^= nums[i];
        int one = 1;
        while( !(x & one))//根据最后一位1将数组分成两部分，前半部分该为为1，后半部分该位为0
            one <<= 1;
        int i = 0,j = nums.size()-1;
        while(i < j){
            while(nums[i] & one) i++;
            while(!(nums[j] & one)) j--;
            if(i<j)
                swap(nums[i],nums[j]);
        }
        ret.push_back(findSingle(nums,0,i));
        ret.push_back(findSingle(nums,i,nums.size()));
        return ret;
    }
    int findSingle(vector<int> & nums,int start,int end){//只有一个数字出现一次，其他两次，找出该数字
        int x = 0;
        for(int i=start;i<end; i++)
            x ^= nums[i];
        return x;
    }
};


//solution

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret;
        if(nums.empty())
            return ret;
        int x = 0;
        for(size_t i =0; i< nums.size(); i++)
            x ^= nums[i];
        x &= ~(x-1);
        int a=0,b=0;
        for(size_t i =0; i< nums.size(); i++){//根据最后一位的不同，用两个不同的数字去异或数组的元素，
            if(nums[i] & x)
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        ret.push_back(a);
        ret.push_back(b);
        return ret;
    }
};