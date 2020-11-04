func canJump(nums []int) bool {
	max := 0
	for i, n := range nums {
		if i > max {
			return false
		}
		if i == len(nums)-1 {
			break
		}
		if i+n > max {
			max = i + n
		}
	}
	return true
}
