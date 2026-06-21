class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            // if duplicates (the character alr exists), shrink the window from the left until the duplicate is removed
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                // increase left or shrink the window until no more duplicates
                left++;
            }

            // if no duplicates, add the character to the set
            charSet.insert(s[right]);

            // right-left+1 counts the total elements currently in the set
            maxLength = max(maxLength, right-left+1);
        }

        return maxLength;
    }
};