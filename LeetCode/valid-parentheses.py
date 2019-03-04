class Solution:
    def isValid(self, s: str) -> bool:
        left = ['(', '[', '{']
        right = [')', ']', '}']
        result = {')':'(', ']':'[','}':'{'}
        con = []
        for i in s:
            if i in left:
                con.append(i)
            else:
                if len(con)==0 or result[i]!=con[-1]:
                    return False
                con.pop()
        else:
            if len(con)!=0:
                return False
            return True


bool isValid(char* s) {
      int length = 0;
    while (*(s + length)) length++;
    if(length==0) return 1;
    char *p;
        p = (char *)malloc(length*sizeof(char));

    //memset(p, ' ', length / 2);
    int i, a = 0;
    for (i = 0; i < length; i++) {
        if (*(s + i) == '(' || *(s + i) == '{' || *(s + i) == '[') {
                        if(a==length-1) return 0;
            *(p + a) = *(s + i);
            a++;
        } else {
            if(a==0) return 0;
            if (*(p+a-1)==*(s+i)-1 ||*(p+a-1)==*(s+i)-2)
                a--;
            else
                return 0;
        }
    }
    if (a)
    {
        return 0;
    }
    return 1;
}