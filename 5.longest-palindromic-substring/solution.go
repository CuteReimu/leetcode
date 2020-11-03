func longestPalindrome(s string) string {
	t := "#"
	for _, c := range s {
		t += string(c)
		t += "#"
	}
	t += "#"
	s = t
	var ans string
	length := 0
	for i := range s {
		j := 1
		for ; i-j >= 0 && i+j < len(s) && s[i-j] == s[i+j]; j++ {
		}
		if j*2-1 > length {
			length = j*2 - 1
			ans = s[i-j+1 : i+j]
		}
	}
	return strings.Replace(ans, "#", "", -1)
}
