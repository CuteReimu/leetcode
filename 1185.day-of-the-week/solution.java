import java.util.Calendar;
class Solution {
    private static String[] W = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    private static int[] M = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    public String dayOfTheWeek(int day, int month, int year) {
        boolean isRun = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
        int D = 0;
        for (int i = 1; i < month; i++)
            D += M[i];
        D += year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) && month > 2 ? day + 1 : day;
        return W[(year - 1 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + D) % 7];
    }
}
