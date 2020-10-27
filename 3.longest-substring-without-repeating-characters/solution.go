func lengthOfLongestSubstring(s string) int {
	var cache [128]int
	i := 0
	maxLen := 0
	curLen := 0
	for _, c := range s {
		tmp := c
		cache[tmp]++
		curLen++
		if cache[tmp] > 1 {
			for {
				cache[s[i]]--
				curLen--
				i++
				if cache[tmp] <= 1 {
					break
				}
			}
		}
		if curLen > maxLen {
			maxLen = curLen
		}
	}
	return maxLen
}
