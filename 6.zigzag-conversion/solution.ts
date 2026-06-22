function convert(s: string, numRows: number): string {
    if (numRows == 1) {
        return s
    }

    const rows: string[] = [];

    for (let i = 0; i < numRows && i < s.length; i++) {
        rows.push("");
    }

    let curRow = 0;
    let goingDown = false;

    for (const c of s) {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows-1) {
            goingDown = !goingDown;
        }
        if (goingDown) curRow++;
        else curRow--;
    }

    return rows.join("");
};