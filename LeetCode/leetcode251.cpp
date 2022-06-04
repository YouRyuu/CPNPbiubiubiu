class Vector2D {
public:
    vector<vector<int>> v;
    int oindex, iindex;
    Vector2D(vector<vector<int>>& vec) :v(vec){       
        oindex = 0;
        iindex = 0; 
    }
    
    int next() {
        hasNext();
        return v[oindex][iindex++];
    }
    
    bool hasNext() {
        while(oindex<v.size() && iindex==v[oindex].size())
        {
            iindex = 0;
            ++oindex;
        }
        return oindex<v.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
