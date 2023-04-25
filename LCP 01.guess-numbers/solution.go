func game(guess []int, answer []int) (count int) {
	if guess[0] == answer[0] {
		count++
	}
	if guess[1] == answer[1] {
		count++
	}
	if guess[2] == answer[2] {
		count++
	}
	return
}
