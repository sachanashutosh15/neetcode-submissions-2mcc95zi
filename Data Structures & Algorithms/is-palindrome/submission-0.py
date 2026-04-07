class Solution:
    def isAlphaNum(self, c):
        return ord('A') <= ord(c) <= ord('Z') or ord('a') <= ord(c) <= ord('z') or ord('0') <= ord(c) <= ord('9')

    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        lowerS = s.lower()
        while i < j:
            if not self.isAlphaNum(s[i]):
                i += 1
                continue
            if not self.isAlphaNum(s[j]):
                j -= 1
                continue
            if lowerS[i] != lowerS[j]:
                return False
            i += 1
            j -= 1
        return True