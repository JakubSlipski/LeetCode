#include <vector>
#include <algorithm>

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        // Sort edgeList
        sort(edgeList.begin(), edgeList.end(), [](const auto& a, const auto& b) {
            return a[2] < b[2];
        });
        
        // Sort queries 
        for (auto& query : queries) {
            query.push_back(&query - &queries[0]);
        }
        sort(queries.begin(), queries.end(), [](const auto& a, const auto& b) {
            return a[2] < b[2];
        });
        
        vector<bool> answer(queries.size(), false);
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        int idx = 0;
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            int limit = query[2];
            
            while (idx < edgeList.size() && edgeList[idx][2] < limit) {
                int pu = findParent(edgeList[idx][0], parent);
                int pv = findParent(edgeList[idx][1], parent);
                if (pu != pv) {
                    unionNodes(pu, pv, parent);
                }
                idx++;
            }
            
            answer[query[3]] = findParent(u, parent) == findParent(v, parent);
        }
        
        return answer;
    }
    
private:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] != node) {
            parent[node] = findParent(parent[node], parent);
        }
        return parent[node];
    }
    
    void unionNodes(int u, int v, vector<int>& parent) {
        if (u == v) return;
        if (u < v) {
            parent[v] = u;
        } else {
            parent[u] = v;
        }
    }
};
