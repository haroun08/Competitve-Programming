class Solution {
    class DSU {
        vector<int> parent;
        vector<int> size;
        
    public:
        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            iota(parent.begin(), parent.end(), 0);  
        }
        
         int find(int node) {
             int root = node;
            while (root != parent[root]) {
                root = parent[root];
            }
             while (node != root) {
                int next = parent[node];
                parent[node] = root;
                node = next;
            }
            return root;
        }
        
        bool unite(int a, int b) {
            int rootA = find(a);
            int rootB = find(b);
            if (rootA == rootB) return false; 
            
             if (size[rootA] < size[rootB]) {
                swap(rootA, rootB);
            }
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
            return true;
        }
    };

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        vector<int> result;
        
        for (const auto& edge : edges) {
             int u = edge[0] - 1;
            int v = edge[1] - 1;
            if (!dsu.unite(u, v)) {
                result = edge;  
            }
        }
        return result;
    }
};
