func reorganizeString(S string) string {
	cache := make(map[byte]int)
	for i := 0; i < len(S); i++ {
		cache[S[i]]++
	}
	cache2 := make(map[int][]byte)
	for b, c := range cache {
		cache2[c] = append(cache2[c], b)
	}
	var keys []int
	for c := range cache2 {
		keys = append(keys, c)
	}
	sort.Ints(keys)
	result := make([]byte, len(S))
	i := 0
	for k := len(keys) - 1; k >= 0; k-- {
		c := keys[k]
		bs := cache2[c]
		if c*2 > len(result)+1 {
			return ""
		}
		for _, b := range bs {
			for j := 0; j < c; j++ {
				result[i] = b
				i += 2
				if i >= len(result) {
					i = 1
				}
			}
		}
	}
	return string(result)
}
