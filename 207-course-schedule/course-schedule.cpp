class Solution {
private:
    bool isCycle(vector<vector<int>>& graph, vector<int>& visited, vector<int>& DFSpath, int node) {
        visited[node] = 1;
        DFSpath[node] = 1;

        for(auto nei : graph[node]) {
            if(!visited[nei]) {
                if(isCycle(graph, visited, DFSpath, nei))
                    return true;
            }
            else if(DFSpath[nei]) {
                return true;
            }
        }

        DFSpath[node] = 0;
        return false;
    }


public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto p : prerequisites)
            graph[p[0]].push_back(p[1]);

        vector<int> visited(numCourses, 0);
        vector<int> DFSpath(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(isCycle(graph, visited, DFSpath, i))
                    return false;
            }
        }

        return true;
    }
};