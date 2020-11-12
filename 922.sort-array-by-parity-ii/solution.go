func sortArrayByParityII(A []int) []int {
	p1 := 1
	for p1 < len(A) {
		if A[p1]%2 == 0 {
			p2 := 0
			for p2 <= len(A) {
				if A[p2]%2 != 0 {
					break
				}
				p2 += 2
			}
			A[p1], A[p2] = A[p2], A[p1]
		}
		p1 += 2
	}
	return A
}
