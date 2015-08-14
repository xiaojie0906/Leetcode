class Solution {
public:
    int maxArea(vector<int>& height) {
        assert(height.size() >1);
        int left =height[0],right =height[1];
        int water = 0;
        for(int i =0,j=height.size()-1;i<j ;){
            right = height[j];
            left = height[i];
            water = max(water,(min(right,left))*(j-i));
            if(right <= left)
                j--;
             else
                i++;
        }
        return water;
    }
};