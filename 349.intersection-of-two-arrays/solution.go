func intersection(nums1 []int, nums2 []int) []int {
	m1 := make(map[int]int)
	m2 := make(map[int]int)
	if len(nums1) > len(nums2) {
		nums1, nums2 = nums2, nums1
	}
	for i, n := range nums1 {
		m1[n] = i
	}
	for i, n := range nums2 {
		_, contains := m1[n]
		if contains {
			m2[n] = i
		}
	}
	var keys []int
	for n := range m2 {
		keys = append(keys, n)
	}
	return keys
}
