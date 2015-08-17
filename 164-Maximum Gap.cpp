class Solution {
public:
int maximumGap(vector<int>& nums) {
	int len = nums.size();
	if(len < 2)
		return 0;
	int minv = INT_MAX;
	int maxv = INT_MIN;
	for(int i=0; i< len ; i++){
		minv = min(minv,nums[i]);
		maxv = max(maxv,nums[i]);
	}
	
	int gap = max(1,(maxv-minv) / (len+1));
	int bucket_num = (maxv -minv)/gap +1;//分成这么多桶，其中必有一个空桶，GAP 大于一个桶的距离，保存每个桶中的最大最小值
	int (*bucket) [2] = new int [bucket_num][2];

	for(int i =0; i<bucket_num; i++){
		bucket[i][0] = INT_MAX;
		bucket[i][1] = INT_MIN;
	}
	int bucket_id;
	
	for(int i=0; i< len; i++){
		bucket_id = (nums[i] - minv)/gap;
		bucket[bucket_id][0] = min(bucket[bucket_id][0],nums[i]);
		bucket[bucket_id][1] = max(bucket[bucket_id][1],nums[i]);
	}
	int pre = bucket[0][1];
	int maxgap = 0;
	for(int i = 1; i< bucket_num; i++){
		if(bucket[i][0] != INT_MAX){
			maxgap = max(maxgap,bucket[i][0] - pre);
			pre = bucket[i][1];
		}
	}
	return maxgap;
}
};