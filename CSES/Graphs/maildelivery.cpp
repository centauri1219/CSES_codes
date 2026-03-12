#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        degree[u]++;
        degree[v]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (degree[i] % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    vector<bool> used_edge(m, false);
    vector<int> head(n + 1, 0); 
    stack<int> st;
    vector<int> circuit;

    st.push(1); 

    while (!st.empty()) {
        int u = st.top();
        bool edge_found = false;
        while (head[u]<adj[u].size()) {
            auto [v, edge_idx] = adj[u][head[u]];
            head[u]++; // Advance pointer
            
            if (!used_edge[edge_idx]) {
                used_edge[edge_idx] = true;
                st.push(v);
                edge_found = true;
                break;
            }
        }

        if (!edge_found) {
            circuit.push_back(u);
            st.pop();
        }
    }
    if (circuit.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = circuit.size() - 1; i >= 0; --i) {
            cout << circuit[i] << (i == 0 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}