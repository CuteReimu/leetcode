func isIdealPermutation(nums []int) bool {
	min := make([]int, len(nums))
	min[len(min)-1] = nums[len(nums)-1]
	for i := len(nums) - 2; i >= 0; i-- {
		if nums[i] > min[i+1] {
			min[i] = min[i+1]
		} else {
			min[i] = nums[i]
		}
	}
	for i := range nums {
		if i+2 < len(min) && nums[i] > min[i+2] {
			return false
		}
	}
	return true
}
