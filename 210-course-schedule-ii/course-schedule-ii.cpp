class Solution {
private:
    vector<int> topoSort(unordered_map<int, vector<int>>& adj, vector<int>& indegree, vector<int>& result) {
        queue<int> q;

        for(int i = 0; i < indegree.size(); i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for(auto nei : adj[node]) {
                indegree[nei]--;

                if(indegree[nei] == 0)
                    q.push(nei);
            }
        }

        return result;
    }


public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for(auto& p : prerequisites) {
            int u = p[1];
            int v = p[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int> result;
        topoSort(adj, indegree, result);

        return result.size() == numCourses ? result : vector<int>();
    }
};