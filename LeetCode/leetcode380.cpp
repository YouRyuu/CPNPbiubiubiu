class RandomizedSet {
public:
    map<int, int> m;        //val index
    vector<int> v;
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if(m.count(val)==0)
        {
            v.push_back(val);
            m[val] = v.size()-1;
            return true;
        }
        else
            return false;
    }
    
    bool remove(int val) {
        if(m.count(val)==0)
            return false;
        else
        {
            int index = m[val];
            int bv = v.back();
            v[index] = bv;
            m[bv] = index;
            v.pop_back();
            m.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int randomIndex = rand()%v.size();
        return v[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
