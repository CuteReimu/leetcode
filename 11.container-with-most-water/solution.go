func maxArea(height []int) int {
	i, j := 0, len(height)-1
	temp := min(height[i], height[j]) * (j - i)
	for i < j {
		if height[i] < height[j] {
			i++
		} else {
			j--
		}
		temp = max(temp, min(height[i], height[j])*(j-i))
	}
	return temp
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}
