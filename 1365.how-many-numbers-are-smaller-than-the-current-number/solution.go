func smallerNumbersThanCurrent(nums []int) []int {
	cache := make(map[int][]int)
	for i, num := range nums {
		cache[num] = append(cache[num], i)
	}
	result := make([]int, len(nums))
	sort.Ints(nums)
	for i, num := range nums {
		if i == 0 || nums[i] != nums[i-1] {
			for _, j := range cache[num] {
				result[j] = i
			}
		}
	}
	return result
}
