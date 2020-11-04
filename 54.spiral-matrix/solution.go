func spiralOrder(matrix [][]int) []int {
	if len(matrix) == 0 {
		return []int{}
	}
	length := len(matrix) * len(matrix[0])
	result := make([]int, length, length)
	ii, jj := 0, 1
	matrixI, matrixJ := 0, 0
	dir := 1
	for i := 0; i < len(result); i++ {
		result[i] = matrix[matrixI][matrixJ]
		switch dir {
		case 1:
			if len(matrix[0])-matrixJ-matrixI == 1 {
				dir = 2
				ii, jj = jj, -ii
			}
		case 2:
			if len(matrix)-matrixI == len(matrix[0])-matrixJ {
				dir = 3
				ii, jj = jj, -ii
			}
		case 3:
			if len(matrix)-matrixI-matrixJ == 1 {
				dir = 4
				ii, jj = jj, -ii
			}
		case 4:
			if matrixI-matrixJ == 1 {
				dir = 1
				ii, jj = jj, -ii
			}
		}
		matrixI += ii
		matrixJ += jj
	}
	return result
}
