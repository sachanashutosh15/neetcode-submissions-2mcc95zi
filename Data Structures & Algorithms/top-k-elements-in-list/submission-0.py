class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        numFreqMap = {}
        for num in nums:
            numFreqMap[num] = numFreqMap.get(num, 0) + 1
        sortedPairs = sorted(numFreqMap.items(), key=lambda x: x[1], reverse = True)
        res = []
        for i in range(k):
            res.append(sortedPairs[i][0])
        return res

        