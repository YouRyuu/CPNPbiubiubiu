class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums = sorted(nums)
        sums = 0
        if len(nums) <= 2:
            return nums[0]
        length = len(nums)
        for i in range(0,length,2):
            sums = sums + nums[i]
        return sums

'''
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return sum(nums[::2])
'''