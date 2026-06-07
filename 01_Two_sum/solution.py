class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        seen = {}
        
        for i, num in enumerate(nums):
            complement = target - num

            if complement in seen:
                # return the index of that matching value in the dictionary
                return [seen[complement], i]

            # add the current number and its index to the dictionary
            seen[num] = i

        return []
        