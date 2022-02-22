func sumOfThree(num int64) []int64 {
	if num % 3 != 0 {
		return []int64{}
	}
	num /= 3
	return []int64{num-1, num, num+1}
}
