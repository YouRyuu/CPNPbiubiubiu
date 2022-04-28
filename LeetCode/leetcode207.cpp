class Solution {
public:
    vector<vector<int>> edges;
    vector<int> visited;
    bool ok = true;
    void dfs(int x)
    {
        visited[x] = 1;
        for(int e:edges[x])
        {
            if(visited[e]==0)
            {
                dfs(e);
                if(!ok)
                    return;
            }
            else if(visited[e]==1)
            {
                ok = false;
                return;
            }
        }
        visited[x] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(auto item : prerequisites)
        {
            edges[item[1]].push_back(item[0]);
        }
        for(int i=0; i<numCourses && ok; ++i)
        {
            if(!visited[i])
                dfs(i);
        }
        return ok;
    }
};
