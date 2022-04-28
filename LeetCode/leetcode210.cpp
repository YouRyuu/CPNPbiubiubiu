class Solution {
public:
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> ret;
    bool ok = true;
    void dfs(int n)
    {
        visited[n] = 1;
        for(auto v:edges[n])
        {
            if(visited[v]==1)
            {
                ok = false;
                return;
            }
            else if(visited[v]==0)
            {
                dfs(v);
                if(!ok)
                    return;
            }
        }
        visited[n] = 2;
        ret.push_back(n);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(auto item : prerequisites)
        {
            edges[item[1]].push_back(item[0]);
        }
        for(int i=0; i<numCourses && ok; ++i)
        {
            if(visited[i]==0)
            {
                dfs(i);
            }
            if(!ok)
                return {};
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
