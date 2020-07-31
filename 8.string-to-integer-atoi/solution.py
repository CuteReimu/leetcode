class Solution:
    def myAtoi(self, str: str) -> int:
        str = str.lstrip()
        i = 0
        sig = 1
        dict = {"0": 0, "1": 1, "2": 2, "3": 3, "4": 4, "5": 5, "6": 6, "7": 7, "8": 8, "9": 9}
        if len(str) == 0:
            return 0
        if str[0] == "+":
            i = 1
        elif str[0] == "-":
            i = 1
            sig = -1
        result = 0
        while i < len(str):
            if str[i] not in dict:
                break
            result = result * 10 + dict[str[i]] * sig
            if result >= 2147483648:
                return 2147483647
            if result < -2147483648:
                return -2147483648
            i += 1
        return result
