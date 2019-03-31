class Solution {
    public List<String> commonChars(String[] A) {
               List<String> list = new ArrayList<>();
    int[] res = new int[26];
    for (char c : A[0].toCharArray()) {
        res[c - 'a']++;
    }
    for (int i = 1; i < A.length; i++) {
        int[] temp = new int[26];
        for (char c : A[i].toCharArray()) {
            temp[c - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            res[j] = Math.min(res[j], temp[j]);
        }
    }
    for (int i = 0; i < res.length; i++) {
        if (res[i] > 0) {
            for (int j = 0; j < res[i]; j++) {
                list.add(((char) ('a' + i) + ""));
            }
        }
    }
    return list;
    }
}