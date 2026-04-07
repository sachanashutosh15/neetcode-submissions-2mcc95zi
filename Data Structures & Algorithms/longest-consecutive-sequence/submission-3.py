class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        store = set(nums)
        res = 0
        for num in store:
            if num - 1 not in store:
                curr = num
                while curr + 1 in store:
                    curr += 1
                res = max(res, curr - num + 1)
        return res