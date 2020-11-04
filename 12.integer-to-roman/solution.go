func intToRoman(num int) string {
	var nums [4]int
	nums[0] = num / 1000
	num %= 1000
	nums[1] = num / 100
	num %= 100
	nums[2] = num / 10
	nums[3] = num % 10
	return iToR(nums[0], "M", "", "") + iToR(nums[1], "C", "D", "M") + iToR(nums[2], "X", "L", "C") + iToR(nums[3], "I", "V", "X")
}

func iToR(num int, one, five, ten string) string {
	switch num {
	case 0:
		return ""
	case 1:
		return one
	case 2:
		return one + one
	case 3:
		return one + one + one
	case 4:
		return one + five
	case 5:
		return five
	case 6:
		return five + one
	case 7:
		return five + one + one
	case 8:
		return five + one + one + one
	case 9:
		return one + ten
	}
	return ""
}
