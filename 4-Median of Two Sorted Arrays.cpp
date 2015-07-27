class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		if(m>n)
			return  findMedianSortedArrays(nums2,nums1);

		vector<int> &A = nums1;    
		vector<int> &B = nums2;

		int j = 0,i =0, imin = 0, imax = m;
		i = -1;
		j =-1;
		int maxleft ;
		int minright;
		while(imin <= imax){
			i = (imin+imax)/2;
			j =( m+n +1)/2 -i ;
			if(j>0 && i< m  && B[j-1] > A[i])
				imin  = i+1;
			else if(i>0 && j<n && A[i-1] > B[j])
				imax = i - 1 ;
			else{
				if(0 == i)
					maxleft = B[j-1];
				else if(0 == j)
					maxleft  = A[i-1];
				else
					maxleft = max(A[i-1],B[j-1]);
				if(m == i)
					minright = B[j];
				else if(n == j)
					minright = A[i];
				else
					minright = min(A[i],B[j]);

				if((m+n) & 1) //odd
					return maxleft;
				else
					return (maxleft+minright)/2.0;
			}
		}  
	}
};