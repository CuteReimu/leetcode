class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if len(s) == 0 or len(words) == 0:
            return []
        word_len = len(words[0])
        cache = {}
        for i in range(len(words)):
            if words[i] not in cache:
                cache[words[i]] = 1
            else:
                cache[words[i]] += 1
        result = []
        for i in range(len(s) - word_len * len(words) + 1):
            s0 = s[i:i + word_len]
            if s0 in cache and Solution.match(s[i:i + word_len * len(words)], cache.copy(), word_len):
                result.append(i)
        return result

    @staticmethod
    def match(s: str, cache: {str, int}, word_len: int) -> bool:
        for i in range(0, len(s), word_len):
            s0 = s[i:i + word_len]
            if s0 not in cache:
                return False
            cache[s0] -= 1
            if cache[s0] == 0:
                cache.pop(s0)
        return True
