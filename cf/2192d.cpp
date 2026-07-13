#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> a;
int n;
vector<vector<int> > graph;
vector<int> vi, md;
vector<ll> ans, s, as;

ll dfs(int x, int d) {
    vi[x] = 1;
    int cc = 0, cs = 0;
    ll m1 = 0, m2 = 0, mc = 0;
    for(int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        
        if(vi[y] == 0) {
            cc++;
            cs = y;
            ll t = dfs(y, d+1);
            s[x] += t;
            as[x] += as[y] + t;
            if(md[y] > m1) {
                m1 = md[y];
                md[x] = md[y];
            }
        }
    }
    if(cc == 1) {
        ans[x] = ans[cs] + s[x];
    }
    else if(cc != 0) {
        for(int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if(vi[y] == 0) {
                if(md[y] == m1) {
                    mc++;
                }
                else if(md[y] != m1 && md[y] > m2) {
                    m2 = md[y];
                }
            }
        }
        ll ms = 0, tas = 0;
        for(int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if(vi[y] == 0) {
                tas += as[y];
                ms = max(ms, ans[y] + s[y] - as[y]);
                if(md[y] == m1 && mc == 1) {
                    ms = max(ms, s[y] * (m2-d));
                }
                else {
                    ms = max(ms, s[y] * (m1-d));
                }
            }
        }
        ans[x] = tas + ms;
    }
    else {
        md[x] = d;
    }
    vi[x] = 0;
    as[x] += a[x];
    return s[x] = s[x] + a[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        a.resize(n + 1);
        vi.assign(n + 1, 0);
        ans.assign(n + 1, 0);
        s.assign(n + 1, 0);
        as.assign(n + 1, 0);
        md.assign(n + 1, 0);
        graph.assign(n + 1, vector<int>());
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1, 1);    
        for(int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
        
    }

    return 0;
}
