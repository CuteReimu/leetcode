func findDuplicate(nums []int) int {
	n := len(nums)
	ans := 0
	// 确定二进制下最高位是多少
	bitMax := 31
	for (n-1)>>bitMax != 0 {
		bitMax -= 1
	}
	for bit := 0; bit <= bitMax; bit++ {
		x, y := 0, 0
		for i := 0; i < n; i++ {
			if nums[i]&(1<<bit) != 0 {
				x += 1
			}
			if i >= 1 && (i&(1<<bit) != 0) {
				y += 1
			}
		}
		if x > y {
			ans |= 1 << bit
		}
	}
	return ans
}
