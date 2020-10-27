func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	i := 0
	j := 0
	l := len(nums1) + len(nums2)
	if l == 1 {
		if len(nums1) > 0 {
			return float64(nums1[0])
		}
		return float64(nums2[0])
	}
	cur := 0
	last := 0
	for {
		if i < len(nums1) {
			last = cur
			if j < len(nums2) {
				if nums1[i] <= nums2[j] {
					cur = nums1[i]
					i++
				} else {
					cur = nums2[j]
					j++
				}
			} else {
				cur = nums1[i]
				i++
			}
		} else if j < len(nums2) {
			last = cur
			cur = nums2[j]
			j++
		} else {
			break
		}
		if l%2 == 1 {
			if i+j > (l-1)/2 {
				return float64(cur)
			}
		} else {
			if i+j > l/2 {
				return float64(cur+last) / 2
			}
		}
	}
	return 0.0
}
