class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freqMap, maxF = {}, 0
        n, l, res = len(s), 0, 0
        for r in range(n):
            freqMap[s[r]] = 1 + freqMap.get(s[r], 0)
            maxF = max(maxF, freqMap[s[r]])
            while (r - l + 1 - maxF > k):
                freqMap[s[l]] -= 1
                l += 1
            res = max(res, r - l + 1)
        return res