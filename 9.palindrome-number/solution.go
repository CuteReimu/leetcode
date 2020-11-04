func isPalindrome(x int) bool {
	if x <= 0 {
		return x == 0
	}
	xx := int64(x)
	var a []int64
	for xx > 0 {
		a = append(a, xx%10)
		xx /= 10
	}
	y := int64(0)
	for _, v := range a {
		y = y*10 + v
	}
	return y == int64(x)
}
