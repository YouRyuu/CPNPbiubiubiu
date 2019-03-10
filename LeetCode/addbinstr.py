     
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        c = int(a,2)+int(b,2) #换为十进制
        d = bin(c)            #换为二进制
        return d[2:]    