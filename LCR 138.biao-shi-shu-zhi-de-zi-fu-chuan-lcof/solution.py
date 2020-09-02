class Solution:
    def isNumber(self, s: str) -> bool:
        s = s.strip()
        found_e = s.find('e')
        found_big_e = s.find('E')
        if found_e >= 0 and found_big_e >= 0:
            return False
        found_e = max(found_e, found_big_e)
        if found_e >= 0:
            if s.find('e', found_e + 1) > 0 or s.find('E', found_e + 1) > 0:
                return False
            if not is_int(s[found_e + 1:], True, False):
                return False
            s = s[:found_e]
        if len(s) == 0 or (len(s) == 1 and s[0] == '.') or (len(s) == 2 and (s[0] == '+' or s[0] == '-') and s[1] == '.'):
            return False
        found_dot = s.find('.')
        if found_dot >= 0:
            return is_int(s[:found_dot], True, True) and is_int(s[found_dot + 1:], False, True)
        return is_int(s, True, False)

def is_int(s: str, allow_sig: bool, allow_empty: bool) -> bool:
    if not allow_empty and (len(s) == 0 or (len(s) == 1 and (s[0] == '+' or s[0] == '-'))):
        return False
    for i in range(len(s)):
        if i == 0 and allow_sig and s[i] in ['+', '-']:
            continue
        if s[i] not in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
            return False
    return True
