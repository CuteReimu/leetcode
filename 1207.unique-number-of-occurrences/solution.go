func uniqueOccurrences(arr []int) bool {
	sort.Ints(arr)
	temp := 1
	var counts []int
	for i := 1; i < len(arr); i++ {
		if arr[i-1] != arr[i] {
			counts = append(counts, temp)
			temp = 1
		} else {
			temp++
		}
	}
	counts = append(counts, temp)
	sort.Ints(counts)
	for i := 1; i < len(counts); i++ {
		if counts[i-1] == counts[i] {
			return false
		}
	}
	return true
}
