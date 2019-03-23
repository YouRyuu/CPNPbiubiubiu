class Solution:
    def fib(self, N: int) -> int:
        a = 0
        b = 1
        count = 0
        while(count !=N):
            a, b = b, a+b
            count += 1
        return a
        