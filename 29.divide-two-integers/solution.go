func divide(dividend int, divisor int) int {
	if dividend == 0 {
		return 0
	}
	if divisor == 1 {
		return dividend
	}
	if divisor == -1 {
		if dividend == math.MinInt32 {
			return math.MaxInt32
		}
		return -dividend
	}
	sign := 1
	if dividend < 0 {
		sign *= -1
		dividend *= -1
	}
	if divisor < 0 {
		sign *= -1
		divisor *= -1
	}
	return int(divPos(int64(dividend), int64(divisor))) * sign
}

func divPos(dividend int64, divisor int64) int64 {
	if dividend < divisor {
		return 0
	}
	result := int64(1)
	t := divisor
	for t+t <= dividend {
		t += t
		result += result
	}
	return result + divPos(dividend-t, divisor)
}
