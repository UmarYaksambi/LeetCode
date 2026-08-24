class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = 1e9;
        unordered_map<int, vector<pair<int, int>>> adj;
        vector<int> minTimes(n + 1, inf);

        for(auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adj[u].push_back({v, w});  //src : {dest, wgt}
        }

        priority_queue<pair<int, int>, 
            vector<pair<int, int>>,
            greater<pair<int, int>>> pq;  // time, node
        
        pq.push({0, k});
        minTimes[k] = 0;

        while(!pq.empty()) {
            auto [tm, node] = pq.top();
            pq.pop();

            if(tm > minTimes[node])
                continue;

            for(auto nei : adj[node]) {
                int nTime = tm + nei.second;
                int nNode = nei.first;

                if(nTime < minTimes[nNode]) {
                    pq.push({nTime, nNode});
                    minTimes[nNode] = nTime;
                }
            }
        }

        int maxTime = 0;
        for(int i = 1; i < minTimes.size(); i++) {
            if(minTimes[i] == inf)
                return -1;;

            maxTime = max(maxTime, minTimes[i]);
        }

        return maxTime;
    }
};