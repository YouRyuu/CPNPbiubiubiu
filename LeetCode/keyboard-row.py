class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        first = ['q','w','e','r','t','y','u','i','o','p']
        second = ['a','s','d','f','g','h','j','k','l']
        third = ['z','x','c','v','b','n','m']
        infirst = 0
        insecond = 0
        inthird = 0
        result = []
        ok = 0
        for word in words:
            ok = 0
            infirst = 0
            insecond = 0
            inthird = 0
            for i in word.lower():
                if i in first:
                    if insecond==1 or inthird==1:
                        ok = 1
                        break
                    else:
                        infirst = 1
                elif i in second:
                    if infirst==1 or inthird==1:
                        ok = 1
                        break
                    else:
                        insecond = 1
                else:
                    if infirst==1 or insecond==1:
                        ok = 1
                        break
                    inthird = 1
            if ok == 0:
                result.append(word)
        return result