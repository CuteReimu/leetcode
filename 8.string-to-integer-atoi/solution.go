func myAtoi(s string) int {
	s = strings.Trim(s, " ")
	for i := 1; i < len(s); i++ {
		if s[i] < '0' || s[i] > '9' {
			s = s[0:i]
			break
		}
	}
	if len(s) == 0 {
		return 0
	}
	var sig int64 = 1
	if s[0] == '-' {
		sig = -1
		s = s[1:]
	} else if s[0] == '+' {
		s = s[1:]
	}
	for i := 0; i < len(s); i++ {
		if s[i] != '0' {
			s = s[i:]
			break
		} else if i == len(s)-1 {
			return 0
		}
	}
	if len(s) > 12 {
		if sig == -1 {
			return math.MinInt32
		}
		return math.MaxInt32
	}
	val, err := strconv.ParseInt(strings.Trim(s, " "), 10, 64)
	if err != nil {
		return 0
	}
	val *= sig
	if val > math.MaxInt32 {
		return math.MaxInt32
	} else if val < math.MinInt32 {
		return math.MinInt32
	}
	return int(val)
}
