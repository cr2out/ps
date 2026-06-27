#include <bits/stdc++.h>

using namespace std;

struct p {
    int x, y;
};

void dfs(int x, int n, vector<int> &v, vector<vector<int> > g) {
    v[x] = 1;
    for(int i = 1; i <= n; i++) {
        if(g[x][i] == 1 && v[i] == 0) {
            dfs(i, n, v, g);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;

        vector<vector<int> > g(n+1, vector<int>(n+1)), ng(n+1, vector<int>(n+1));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                char x;
                cin >> x;
                g[i][j] = (int)x - '0';
            }
        }

        vector<p> a;
        vector<int> v(n + 1);
        int imp = 0;
        for(int i = 1; i <= n; i++) {
            if(g[i][i] != 1) {
                imp = 1;
                break;
            }
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                int flag = 0;
                for(int k = 1; k <= n; k++) {
                    if(j == k || i == k) continue;
                    if(g[i][j] == 1 && g[i][k] == 1 && g[k][j] == 1) {
                        flag = 1; 
                    }
                    else if(g[i][j] == 0 && g[i][k] == 1 && g[k][j] == 1) {
                        imp = 1;
                        break;
                    }
                }
                if(!flag && g[i][j] == 1) {
                    a.push_back({i, j});
                    ng[i][j] = 1;
                    ng[j][i] = 1;
                }
            }
        }
        dfs(1, n, v, ng);
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            cnt += v[i];
        }
        if(a.size() != n - 1 || cnt != n || imp) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
            for(int i = 0; i < a.size(); i++) {
                cout << a[i].x << " " << a[i].y << '\n';
            }
        }
    }
}
