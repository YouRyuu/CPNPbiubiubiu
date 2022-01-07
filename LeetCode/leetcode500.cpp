class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        unordered_set l1 = {'q', 'w','r','e','t','y','u','i','o','p'};
        unordered_set l2 = {'a','s','d','f','g','h','j','k','l'};
        unordered_set l3 = {'z', 'x', 'c', 'v', 'b','n','m'};
        for(auto &word:words)
        {
            int il1=0, il2=0, il3=0;
            for(auto &c:word)
            {                
                if(l1.count(c)>0) 
                {
il1=1;continue;
                }
                if(l2.count(c)>0)
                {il2=1;
continue;
                } 
                if(l3.count(c)>0) 
                {il3=1;
continue;
                }
                
            }
            if(il1+il2+il3==1)
            ret.push_back(word);
        }
        return ret;
    }
};
