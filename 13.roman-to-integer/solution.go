func romanToInt(s string) int {
	a := make([]int, len(s), len(s))
	for i, c := range s {
		switch c {
		case 'I':
			a[i] = 1
		case 'V':
			a[i] = 5
		case 'X':
			a[i] = 10
		case 'L':
			a[i] = 50
		case 'C':
			a[i] = 100
		case 'D':
			a[i] = 500
		case 'M':
			a[i] = 1000
		}
	}
	sum := 0
	for i, c := range a {
		if i+1 < len(a) && c < a[i+1] {
			sum -= c
		} else {
			sum += c
		}
	}
	return sum
}
