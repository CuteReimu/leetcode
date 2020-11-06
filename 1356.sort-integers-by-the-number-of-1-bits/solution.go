func sortByBits(arr []int) []int {
	for i, val := range arr {
		arr[i] = val + 100000*countOne(val)
	}
	sort.Ints(arr)
	for i := range arr {
		arr[i] %= 100000
	}
	return arr
}

func countOne(val int) int {
	num := 0
	for val > 0 {
		num++
		val &= val - 1
	}
	return num
}
