func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	m := make(map[int][]int)
	for i, n := range nums {
		m[n] = append(m[n], i)
	}
	var result [][]int
	for i, n := range nums {
		if i > 0 && n == nums[i - 1] {
			continue
		}
		for j := i + 1; j < len(nums); j++ {
			if j > i + 1 && nums[j] == nums[j - 1] {
				continue
			}
			if ks,ok := m[-n-nums[j]]; ok {
				for _, k := range ks {
					if k > j {
						result = append(result, []int{n, nums[j], -n-nums[j]})
						break
					}
				}
			}
		}
	}
	return result
}
