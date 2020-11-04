func insert(intervals [][]int, newInterval []int) [][]int {
	m := make(map[int]int)
	for _, interval := range intervals {
		m[interval[0]]++
		m[interval[1]]--
	}
	m[newInterval[0]]++
	m[newInterval[1]]--
	var keys []int
	for k := range m {
		keys = append(keys, k)
	}
	sort.Ints(keys)
	temp := 0
	var last int
	var result [][]int
	for _, key := range keys {
		if m[key] > 0 {
			if temp == 0 {
				last = key
			}
			temp += m[key]
		} else if m[key] < 0 {
			temp += m[key]
			if temp == 0 {
				result = append(result, []int{last, key})
			}
		} else {
			if temp == 0 {
				result = append(result, []int{key, key})
			}
		}
	}
	return result
}
