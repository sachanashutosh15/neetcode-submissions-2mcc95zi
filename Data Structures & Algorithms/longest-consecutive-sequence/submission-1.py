class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        store = set(nums)
        res = 0
        for num in nums :
            i=1
            while num + i in store :
                i += 1
            res = max(res, i)
        return res