func countPrimes(n int) int {
	if n <= 2 {
		return 0
	} else if n == 3 {
		return 1
	}
	p := make([]bool, n)
	p[0] = true
	p[1] = true
	realP := make([]int, 0)
	for i := 2; i < n; i++ {
		if !p[i] {
			realP = append(realP, i)
		}
		for j := 0; j < len(realP); j++ {
			val := realP[j] * i
			if val >= n {
				break
			}
			p[val] = true
		}
	}
	return len(realP)
}
