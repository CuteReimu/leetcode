class Solution {
    public int reverse(int x) {
        int sign = (int) Math.signum(x);
        x = Math.abs(x);
        long answer = 0;
        while (x > 0)
        {
        	answer = answer * 10 + x % 10;
        	x /= 10;
        }
        answer *= sign;
        return answer > Integer.MAX_VALUE || answer < Integer.MIN_VALUE ? 0 : (int) answer;
    }
}
