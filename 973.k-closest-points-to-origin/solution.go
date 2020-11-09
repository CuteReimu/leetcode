type PointList [][]int

func (p PointList) Len() int {
	return len(p)
}

func (p PointList) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func (p PointList) Less(i, j int) bool {
	return p[i][0]*p[i][0]+p[i][1]*p[i][1] < p[j][0]*p[j][0]+p[j][1]*p[j][1]
}

func kClosest(points [][]int, K int) [][]int {
	sort.Sort(PointList(points))
	var result [][]int
	for i := 0; i < K; i++ {
		result = append(result, points[i])
	}
	return result
}
