function lengthOfLongestSubstring(s: string): number {
    const count = new Map<number, number>();
    let start = 0, maxLen = 0;
    for (let i = 0; i < s.length; i++) {
        const char = s.charCodeAt(i);
        const c = count.get(char) ?? 0;
        count.set(char, c+1);
        if (c) {
            let ch: number;
            do {
                ch = s.charCodeAt(start);
                count.set(ch, count.get(ch)! - 1);
                start++;
            } while (ch != s.charCodeAt(i));
        } else {
            maxLen = Math.max(maxLen, i - start + 1);
        }
    }
    return maxLen;
};