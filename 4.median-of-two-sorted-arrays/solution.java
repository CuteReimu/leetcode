class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if ((nums1.length + nums2.length) % 2 == 0)
		{
			int value1 = findSpecificSortedArrays(nums1,0,nums1.length,nums2,0,nums2.length,(nums1.length+nums2.length)/2);
			int value2 = findSpecificSortedArrays(nums1,0,nums1.length,nums2,0,nums2.length,(nums1.length+nums2.length)/2+1);
			return (value1 + value2) / 2.0;
		} else
			return findSpecificSortedArrays(nums1,0,nums1.length,nums2,0,nums2.length,(nums1.length+nums2.length+1)/2);
    }
    
	public int findSpecificSortedArrays(int[] nums1, int left1, int len1, int[] nums2, int left2, int len2, int k)
	{
        if (len1 > len2)
			return findSpecificSortedArrays(nums2, left2, len2, nums1, left1, len1, k);
		if (len1 == 0)
			return nums2[left2 + k - 1];
		if (k == 1)
			return Math.min(nums1[left1], nums2[left2]);
		int index1 = Math.min((k - 1) / 2, len1 - 1);
		int num1 = nums1[left1 + index1];
		int num2 = nums2[left2 + k - index1 - 2];
		if (num1 < num2)
			return findSpecificSortedArrays(nums1, left1 + index1 + 1, len1 - index1 - 1, nums2, left2, len2, k - index1 - 1);
		else if (num1 > num2)
			return findSpecificSortedArrays(nums1,left1,len1,nums2,left2+k-index1-1,len2-k+index1+1,index1+1);
		return num1;
	}

}
