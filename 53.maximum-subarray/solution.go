func maxSubArray(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	maxVal := nums[0]
	for i := 1; i < len(nums); i++ {
		if nums[i-1] > 0 {
			nums[i] += nums[i-1]
		}
		if nums[i] > maxVal {
			maxVal = nums[i]
		}
	}
	return maxVal
}
