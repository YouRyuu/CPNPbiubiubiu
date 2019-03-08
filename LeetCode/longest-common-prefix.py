class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        result = ''
        index = 0
        while True:
            try:
                for i in range(len(strs) - 1):
                    if strs[0][index] != strs[i+1][index]:
                        return result
                result +=strs[0][index]
                index += 1
            except:
                return result