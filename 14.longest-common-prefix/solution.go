func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	i := 0
	for {
		if i >= len(strs[0]) {
			return strs[0][0:i]
		}
		for j := 1; j < len(strs); j++ {
			if i >= len(strs[j]) || strs[j][i] != strs[0][i] {
				return strs[0][0:i]
			}
		}
		i++
	}
	return strs[0]
}
