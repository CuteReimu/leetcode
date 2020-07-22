class Solution(object):
    def minArray(self, numbers):
        size = len(numbers)
        if numbers[0] < numbers[size - 1]:
            return numbers[0]
        last = numbers[0]
        for i in numbers:
            if last > i:
                return i
            else:
                last = i
        return numbers[0]
        """
        :type numbers: List[int]
        :rtype: int
        """
