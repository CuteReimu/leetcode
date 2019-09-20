class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] count = new int[5];
        for (char c : text.toCharArray()) {
            switch (c) {
                case 'b': count[0]++; break;
                case 'a': count[1]++; break;
                case 'l': count[2]++; break;
                case 'o': count[3]++; break;
                case 'n': count[4]++; break;
            }
        }
        int val = count[0];
        val = Math.min(val, count[1]);
        val = Math.min(val, count[2] / 2);
        val = Math.min(val, count[3] / 2);
        val = Math.min(val, count[4]);
        return val;
    }
}
