function reverse(x: number): number {
    if (x == 0) return 0;
    let s = x.toString();
    const maxInt = (2**31-1).toString();
    const minInt = (-(2**31)).toString();
    if (x > 0) {
        s = s.split('').reverse().join('');
        if (s.length > maxInt.length || s.length == maxInt.length && s > maxInt)
            return 0;
        return Number(s)
    } else {
        s = "-" + s.slice(1).split('').reverse().join('');
        if (s.length > minInt.length || s.length == minInt.length && s > minInt.toString())
            return 0;
        return Number(s);
    }
};