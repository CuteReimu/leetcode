func reverse(x int) int {
	if x == 0 {
		return 0
	}
	var sig int64 = 1
	if x < 0 {
		sig = -1
		x = -x
	}
	x2 := int64(x)
	arr := make([]int64, 0, 12)
	for x2 > 0 {
		arr = append(arr, x2%10)
		x2 /= 10
	}
	ret := int64(0)
	for _, val := range arr {
		ret = ret*10 + val
	}
	ret *= sig
	if ret < math.MinInt32 || ret > math.MaxInt32 {
		return 0
	}
	return int(ret)
}
