class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ret;
        int len = expression.size();
        if(len<=2)
        {
            ret.push_back(stoi(expression));
            return ret;
        }
        for(int i=0; i<len; ++i)
        {
            char c = expression[i];
            if(c=='+' || c=='-' || c=='*')
            {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                for(auto l:left)
                {
                    for(auto r:right)
                    {
                        switch(c)
                        {
                            case '+':
                                ret.push_back(l+r);
                                break;
                            case '-':
                                ret.push_back(l-r);
                                break;
                            case '*':
                                ret.push_back(l*r);
                                break;
                        }
                    }
                }
            }
        }
        return ret;
    }
};
