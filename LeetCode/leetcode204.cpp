// class Solution {
// public:
//     bool isPrime(int x)
//     {
//         for(int i=2; i*i<=x; ++i)
//         {
//             if(x%i==0)
//                 return false;
//         }
//         return true;
//     }

//     int countPrimes(int n) {
//         int ans = 0;
//         for(int i=2; i<n; ++i)
//         {
//             if(isPrime(i))
//                 ++ans;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans += 1;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};
