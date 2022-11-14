func splitArraySameAverage(nums []int) bool {
	if len(nums) < 2 {
		return false
	}
	sum := 0
	for _, n := range nums {
		sum += n
	}
	if sum%len(nums) == 0 {
		for _, n := range nums {
			if n == sum/len(nums) {
				return true
			}
		}
	}
	sort.Ints(nums)
	cache := make(map[int]int)
	for i, n := range nums {
		if v, ok := cache[n]; !ok || v > i {
			cache[n] = i
		}
	}
	for i := 2; i <= len(nums)/2; i++ {
		if sum*i%len(nums) == 0 {
			for j, n := range nums {
				if idx, ok := cache[sum*i/len(nums)-n]; ok && idx < j {
					return true
				}
			}
		}
		cache2 := make(map[int]int)
		for n, idx := range cache {
			for j := idx + 1; j < len(nums); j++ {
				if v, ok := cache2[n+nums[j]]; !ok || v > j {
					cache2[n+nums[j]] = j
				}
			}
		}
		cache = cache2
	}
	return false
}
