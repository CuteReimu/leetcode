func validMountainArray(A []int) bool {
	i := 1
	j := 0
	for ; i < len(A); i++ {
		if A[i-1] == A[i] {
			return false
		} else if A[i-1] > A[i] {
			j = i - 1
			break
		}
	}
	for ; i < len(A); i++ {
		if A[i-1] == A[i] {
			return false
		} else if A[i-1] < A[i] {
			break
		}
	}
	return i == len(A) && j > 0 && j < len(A)-1
}
