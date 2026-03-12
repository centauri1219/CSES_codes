#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<string> grid;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int r,int c) {
    grid[r][c]='#';
    for (int i =0; i<4;i++) {
        int nr = r+dx[i];
        int nc = c + dy[i];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] =='.') {
            dfs(nr, nc);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!(cin>> n>> m)) return 0;
    grid.resize(n);
    for (int i = 0; i <n; i++) {
        cin>>grid[i];
    }

    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                rooms++;
                dfs(i, j);
            }
        }
    }

    cout<<rooms << "\n";
    return 0;
}