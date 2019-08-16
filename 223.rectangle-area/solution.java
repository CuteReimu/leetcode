class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int[] vLine = {A, C, E, G};
        int[] hLine = {B, D, F, H};
        Arrays.sort(vLine);
        Arrays.sort(hLine);
        if (A == vLine[0] && C == vLine[1] || A == vLine[2] && C == vLine[3] || B == hLine[0] && D == hLine[1] || B == hLine[2] && D == hLine[3]) {
            return (D - B) * (C - A) + (H - F) * (G - E);
        }
        return (D - B) * (C - A) - (vLine[2] - vLine[1]) * (hLine[2] - hLine[1]) + (H - F) * (G - E);
    }
}
