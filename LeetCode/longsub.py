def lengthOfLongestSubstring(s: str) -> int:
    result = {}
    length = 0
    j = 0
    while True:
        for index, value in enumerate(s[j:]):
            if value not in result:
                result[value] = index
            else:
                j = result[value] + 1 + j
                length = max(len(result), length)
                result = {}
                break
        if j == len(s) -1:
            return length

print(lengthOfLongestSubstring("pwwkew"))
