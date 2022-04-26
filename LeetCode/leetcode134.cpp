class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i=0;
        while(i<n)
        {
            int count = 0;
            int sumCost = 0;
            int sumGas = 0;
            while(count < n)
            {
                int j = (i + count)%n;
                sumCost += cost[j];
                sumGas += gas[j];
                if(sumCost > sumGas)
                    break;
                ++count;
            }
            if(count==n)
                return i;
            else
                i = i + count + 1;
        }
        return -1;
    }
};
