func moveZeroes(nums []int) {
	j := 0
	for _, n := range nums {
		if n != 0 {
			nums[j] = n
			j++
		}
	}
	for ; j < len(nums); j++ {
		nums[j] = 0
	}
}
