func islandPerimeter(grid [][]int) int {
	perimeter := 0
	for i, line := range grid {
		for j, value := range line {
			if value == 1 {
				if i-1 < 0 || grid[i-1][j] == 0 {
					perimeter++
				}
				if i+1 >= len(grid) || grid[i+1][j] == 0 {
					perimeter++
				}
				if j-1 < 0 || grid[i][j-1] == 0 {
					perimeter++
				}
				if j+1 >= len(line) || grid[i][j+1] == 0 {
					perimeter++
				}
			}
		}
	}
	return perimeter
}
