class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), -1);
        int RED = 0;
        int BLUE = 1;
        queue<int> q;

        for(int i = 0; i < graph.size(); i++) {  
            if(colors[i] == -1) {
                q.push(i);
                colors[0] = RED; 
            }
            
            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(auto nei : graph[node]) {
                    if(colors[nei] == -1) {
                        q.push(nei);
                        colors[nei] = !colors[node];
                    }
                    else if(colors[nei] == colors[node])
                        return false;
                }
            }
        }

        return true;
    }
};