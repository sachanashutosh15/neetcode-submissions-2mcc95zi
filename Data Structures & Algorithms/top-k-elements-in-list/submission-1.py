class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        numFreqMap = {}
        for num in nums:
            numFreqMap[num] = numFreqMap.get(num, 0) + 1
        heap = []
        for num in numFreqMap.keys():
            heapq.heappush(heap, (numFreqMap[num], num))
            if len(heap) > k:
                heapq.heappop(heap)
        res = []
        for i in range(k):
            res.append(heapq.heappop(heap)[1])
        return res

        