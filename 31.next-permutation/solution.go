func nextPermutation(nums []int)  {
	i := len(nums) - 1
	for ; i > 0; i-- {
		if nums[i-1] < nums[i] {
			for j := len(nums) - 1; j >= 0; j-- {
				if nums[j] > nums[i-1] {
					nums[i-1],nums[j] = nums[j],nums[i-1]
					break
				}
			}
			break
		}
	}
	sort.Ints(nums[i:])
}
