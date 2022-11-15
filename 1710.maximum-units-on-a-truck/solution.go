func maximumUnits(boxTypes [][]int, truckSize int) (ret int) {
	sort.Sort(A(boxTypes))
	size := 0
	for _, a := range boxTypes {
		if truckSize-size > a[0] {
			size += a[0]
			ret += a[0] * a[1]
		} else {
			ret += (truckSize - size) * a[1]
			break
		}
	}
	return
}

type A [][]int

func (a A) Len() int {
	return len(a)
}

func (a A) Less(i, j int) bool {
	return a[i][1] > a[j][1]
}

func (a A) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}
