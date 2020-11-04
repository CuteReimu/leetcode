func isMatch(s string, p string) bool {
	return isMatch2(s, p, 0, 0)
}

func isMatch2(s, p string, i, j int) bool {
	for ; j < len(p); j++ {
		if j+1 >= len(p) || p[j+1] != '*' {
			if i >= len(s) || (p[j] != '.' && s[i] != p[j]) {
				return false
			}
			i++
		} else {
			if isMatch2(s, p, i, j+2) {
				return true
			}
			for ; i < len(s) && (p[j] == '.' || s[i] == p[j]); i++ {
				if isMatch2(s, p, i+1, j+2) {
					return true
				}
			}
			return false
		}
	}
	return i == len(s)
}
