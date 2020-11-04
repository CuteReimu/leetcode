func myPow(x float64, n int) float64 {
	if n == 0 {
		return 1
	} else if n < 0 {
		return 1 / myPow(x, -n)
	}
	return myPow2(x, n, make(map[int]float64))
}

func myPow2(x float64, n int, m map[int]float64) float64 {
	if n == 1 {
		return x
	}
	if val, ok := m[n]; ok {
		return val
	}
	val := myPow2(x, n/2, m) * myPow2(x, n-n/2, m)
	m[n] = val
	return val
}
