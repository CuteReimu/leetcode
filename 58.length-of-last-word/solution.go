func lengthOfLastWord(s string) int {
	if len(s) == 0 {
		return 0
	}
	last := 0
	max := 0
	for i, c := range s {
		if c == ' ' {
			if i - last > 0 {
				max = i - last
			}
			last = i + 1
		}
	}
	if len(s)- last > 0 {
		max = len(s) - last
	}
	return max
}
