func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func expand(s string, left int, right int) int {
	for left >= 0 && right < len(s) && s[left] == s[right] {
		left--
		right++
	}
	return (right - left - 2) / 2
}

func longestPalindrome(s string) string {
	start, end := 0, -1
	t := "#"
	for _, c := range s {
		t += string(c)
		t += "#"
	}
	t += "#"
	s = t
	var armLens []int
	right, j := -1, -1
	for i := 0; i < len(s); i++ {
		var curArmLen int
		if right >= i {
			iSym := j*2 - i
			minArmLen := min(armLens[iSym], right-i)
			curArmLen = expand(s, i-minArmLen, i+minArmLen)
		} else {
			curArmLen = expand(s, i, i)
		}
		armLens = append(armLens, curArmLen)
		if i+curArmLen > right {
			j = i
			right = i + curArmLen
		}
		if curArmLen*2+1 > end-start {
			start = i - curArmLen
			end = i + curArmLen
		}
	}

	var ans string
	for i := start; i <= end; i++ {
		if s[i] != '#' {
			ans += string(s[i])
		}
	}
	return ans
}
