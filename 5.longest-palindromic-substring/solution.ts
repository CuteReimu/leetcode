function longestPalindrome(s: string): string {
    let t = "#";
    for (const c of s) {
        t += c;
        t += "#";
    }
    t += "#";
    s = t;
    let ans = "";
    let length = 0;
    for (let i = 0; i < s.length; i++) {
        let j = 1;
        while (i-j >= 0 && i+j < s.length && s[i-j] == s[i+j]) j++;
        if (j*2-1 > length) {
            length = j*2 - 1;
            ans = s.slice(i-j+1, i+j);
        }
    }
    return ans.replace(/#/g, "");
};