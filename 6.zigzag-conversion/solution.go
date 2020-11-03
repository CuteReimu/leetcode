func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}

	var rows []string

	for i := 0; i < numRows && i < len(s); i++ {
		rows = append(rows, "")
	}

	curRow := 0
	goingDown := false

	for _, c := range s {
		rows[curRow] += string(c)
		if curRow == 0 || curRow == numRows-1 {
			goingDown = !goingDown
		}
		if goingDown {
			curRow++
		} else {
			curRow--
		}
	}

	ret := ""
	for _, row := range rows {
		ret += row
	}
	return ret
}
