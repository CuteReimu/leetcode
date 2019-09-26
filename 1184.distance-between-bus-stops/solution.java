class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        if (start == destination) return 0;
        int sum = 0;
        for (int i : distance)
            sum += i;
        int a = start <= destination ? start : destination;
        int b = start <= destination ? destination : start;
        int sum2 = 0;
        for (int i = a; i < b; i++)
            sum2 += distance[i];
        return Math.min(sum2, sum - sum2);
    }
}
