class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_set = set() # faster than using list
        left = 0
        max_length = 0

        # right will automatically increments from 0 to the end of the string
        for right in range(len(s)):
            while s[right] in char_set:
                char_set.remove(s[left])
                left += 1
            
            char_set.add(s[right])

            max_length = max(max_length, right - left + 1)
        
        return max_length

        