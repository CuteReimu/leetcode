class TrieNode:
    def __init__(self):
        self.next = {}

    def __contains__(self, s: str) -> bool:
        if len(s) == 0:
            return "\0" in self.next
        nxt = self.next.get(s[0])
        if nxt is None:
            return False
        return nxt.find(s[1:])

    def get(self, s: str):
        if len(s) == 0:
            return self.next.get("\0")
        nxt = self.next.get(s[0])
        if nxt is None:
            return None
        return nxt.get(s[1:])

    def append(self, index: int, s: str) -> None:
        if len(s) == 0:
            self.next["\0"] = index
        else:
            node = self.next.get(s[0])
            if node is None:
                node = TrieNode()
                self.next[s[0]] = node
            node.append(index, s[1:])


class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        head = TrieNode()
        for i in range(len(words)):
            head.append(i, words[i])
        result = []
        for i in range(len(words)):
            word = words[i]
            if word == word[::-1]:
                for j in range(len(words)):
                    if i != j and len(words[j]) == 0:
                        result.append([i, j])
                        result.append([j, i])
            for k in range(1, len(word) + 1):
                if word[k:] == word[-1:k - 1:-1]:
                    j = head.get(word[k - 1::-1])
                    if j is not None and j != i:
                        result.append([i, j])
            for k in range(1, len(word)):
                if word[0:k] == word[k-1::-1]:
                    j = head.get(word[:k-1:-1])
                    if j is not None and j != i:
                        result.append([j, i])
        return result
