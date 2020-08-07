class Solution:
    def intToRoman(self, num: int) -> str:
        nums = [num // 1000, num // 100 % 10, num // 10 % 10, num % 10]
        result = duplicate('M', nums[0])
        if nums[1] == 9:
            result += 'CM'
        elif nums[1] >= 5:
            result += 'D'
            result += duplicate('C', nums[1] - 5)
        elif nums[1] == 4:
            result += 'CD'
        else:
            result += duplicate('C', nums[1])
        if nums[2] == 9:
            result += 'XC'
        elif nums[2] >= 5:
            result += 'L'
            result += duplicate('X', nums[2] - 5)
        elif nums[2] == 4:
            result += 'XL'
        else:
            result += duplicate('X', nums[2])
        if nums[3] == 9:
            result += 'IX'
        elif nums[3] >= 5:
            result += 'V'
            result += duplicate('I', nums[3] - 5)
        elif nums[3] == 4:
            result += 'IV'
        else:
            result += duplicate('I', nums[3])
        return result

def duplicate(s: str, i: int) -> str:
    return "" if i <= 0 else duplicate(s, i-1) + s
