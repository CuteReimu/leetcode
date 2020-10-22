func twoSum(nums []int, target int) []int {
	counts := make(map[int][]int)
	for i, n := range nums {
		counts[n] = append(counts[n], i)
	}
	for i, n := range nums {
		js := counts[target-n]
		for _, j := range js {
			if i != j {
				return []int{i, j}
			}
		}
	}
	return []int{}
}
