func findRotateSteps(ring string, key string) int {
	ringCache := make(map[uint8][]int)
	for i := 0; i < len(ring); i++ {
		ringCache[ring[i]] = append(ringCache[ring[i]], i)
	}
	return findRotate(ringCache, len(ring), key, 0, 0, make(map[int]int))
}

func findRotate(ringCache map[uint8][]int, ringLen int, key string, ringPos int, keyPos int, cache map[int]int) int {
	if keyPos == len(key) {
		return 0
	}
	k := ringPos*1000 + keyPos
	if v, ok := cache[k]; ok {
		return v
	}
	first := true
	minVal := 0
	for _, i := range ringCache[key[keyPos]] {
		l := min((ringPos-i+ringLen)%ringLen, (i-ringPos+ringLen)%ringLen)
		ll := l + findRotate(ringCache, ringLen, key, i, keyPos+1, cache)
		if first {
			first = false
			minVal = ll
		} else if ll < minVal {
			minVal = ll
		}
	}
	cache[k] = minVal + 1
	return minVal + 1
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
