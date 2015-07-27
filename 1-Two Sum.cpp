class Solution {
public:
   vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> answer;
        vector<int> copy = numbers;
        int left=0;
        int right=numbers.size()-1;
        sort(numbers.begin(), numbers.end());
        while(left<right){
            if(numbers[left]+numbers[right] == target){
                break;
            }
            else if(numbers[left] + numbers[right] > target)
                right--;
            else
                left++;
        }
        int i;
        int ltag =1,rtag =1;
        for( i=0;i<copy.size()&&(ltag||rtag);i++){
            if(copy[i] == numbers[left]){
                answer.push_back(i+1);
                ltag =0;
            }
            else
                if(copy[i] == numbers[right]){
                    answer.push_back(i+1);
                    rtag =0;
                }             
        }
        return answer;
    }
};