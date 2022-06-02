class TwoSum {
public:
    vector<int> v;
    bool needsort = false;
    TwoSum() {

    }
    
    void add(int number) {
        v.push_back(number);
        needsort = false;
    }
    
    bool find(int value) {
        if(!needsort)
        {
            sort(v.begin(), v.end());
            needsort = true;
        }
        int l = 0, r = v.size()-1;
        while(l<r)
        {
            if(v[l]+v[r]==value)
                return true;
            else if(v[l]+v[r]>value)
                --r;
            else
                ++l;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
