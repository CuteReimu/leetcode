import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int maxArea(int[] height) {
        Integer[] arr = new Integer[height.length];
		for (int i = 0; i < arr.length; i++)
			arr[i] = i;
		Arrays.sort(arr, new Comparator<Integer>(){
			public int compare(Integer o1, Integer o2)
			{
				int value = Integer.compare(height[o2], height[o1]);
				return value == 0 ? Integer.compare(o2, o1) : value;
			}
		});
		int left = Integer.MAX_VALUE;
		int right = Integer.MIN_VALUE;
		int ans = 0;
		for (int i : arr)
		{
			if (left == Integer.MAX_VALUE)
			{
				left = i;
				right = i;
			} else
			{
				ans = Math.max(ans, height[i] * Math.max(i - left, right - i));
				left = Math.min(left, i);
				right = Math.max(right, i);
			}
		}
		return ans;
    }
}
