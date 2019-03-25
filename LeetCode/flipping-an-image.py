class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        for aindex,elems in enumerate(A):
            A[aindex] = A[aindex][::-1]
            for index,elem in enumerate(A[aindex]):
                if A[aindex][index] == 1:
                    A[aindex][index] = 0
                elif A[aindex][index] == 0:
                    A[aindex][index] = 1
        return A