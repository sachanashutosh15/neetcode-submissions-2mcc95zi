class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2:
            return n
        nums.sort()
        res = 1
        i = 0
        streak = 1
        while i + 1 < len(nums):
            if nums[i + 1] == nums[i]:
                i += 1
                continue
            if nums[i + 1] == nums[i] + 1:
                streak += 1
                res = max(res, streak)
            else:
                streak = 1
            i += 1
        return res

