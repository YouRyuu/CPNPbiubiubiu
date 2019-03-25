bool buddyStrings(char* A, char* B) {
    int aindex = 0;
    int bindex = 0;
    int cindex = 0;
    int length = strlen(A)!=strlen(B)?0:strlen(A);
    if(length==0) return false;
    while(aindex<length)
    {
        if(A[aindex]==B[aindex])
        {
            if(aindex!=bindex)
                aindex++;
            else
            {
                aindex++;
                bindex++;
            }
        }
        else
        {
            if(aindex!=bindex)
                if(A[bindex]!=B[aindex]||A[aindex]!=B[bindex])
                    return false;
                else
                {
                    cindex += 1;
                    aindex++;
                }
            aindex++;
        }
    }
    if(aindex==bindex)
    {
        if(aindex==1) return true;
        int flag = 0;
        for(int i=0;i<length;i++)
        {
            flag = A[i]^flag;
        }
        return flag == 0;
    }
    return cindex==1;
}

//offical answer:
/*
class Solution {
    public boolean buddyStrings(String A, String B) {
        if (A.length() != B.length()) return false;
        if (A.equals(B)) {
            int[] count = new int[26];
            for (int i = 0; i < A.length(); ++i)
                count[A.charAt(i) - 'a']++;

            for (int c: count)
                if (c > 1) return true;
            return false;
        } else {
            int first = -1, second = -1;
            for (int i = 0; i < A.length(); ++i) {
                if (A.charAt(i) != B.charAt(i)) {
                    if (first == -1)
                        first = i;
                    else if (second == -1)
                        second = i;
                    else
                        return false;
                }
            }

            return (second != -1 && A.charAt(first) == B.charAt(second) &&
                    A.charAt(second) == B.charAt(first));
        }
    }
}
*/