#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
vector<vector<int> > graph;
vector<int> a, v;
int sq[1000001] = {0};
ll ans = 0;
int n = 0;
 
ll dfs(int x) {
    v[x] = 1;
    vector<ll> child;
    for(int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if(!v[y]) {
            child.push_back(dfs(y));
        }
    }
    ll t1 = 0, t2 = 0, t3 = 0, cc = 0, ccwp = 0;
    for(int i = 0; i < child.size(); i++) {
        t1 += child[i] * child[i];
        t2 += child[i];
        t3 += child[i] * child[i] * child[i];
    }
    ccwp = (t2 * t2 - t1) / 2;
    ll pc = n - (t2 + 1);
    t1 += pc * pc;
    t3 += pc * pc * pc;
    t2 += pc;
    cc = (t2 * t2 - t1) / 2;
    if(sq[a[x]]) {
        ans += cc;
    }
    if(((child.size() >= 2 && pc != 0) || child.size() >= 3) && sq[a[x]]) ans += (t2 * t2 * t2 - 3 * t1 * t2 + 2 * t3) / 6;
    return t2 + 1 - pc;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    for(int i = 1; i * i <= 1000000; i++) {
        sq[i*i] = 1;
    }
    while(T--) {
        cin >> n;
        graph.assign(n + 1, vector<int>());
        a.resize(n + 1);
        v.assign(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        ans = 0;
        dfs(1);
        cout << ans << '\n';
    }
    
    return 0;
}
