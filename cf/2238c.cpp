#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> w(1000000);

ll d(int x, vector<vector<int> > &g, vector<int> &c) {
    ll max = 0, maxp = 0, min = 10000000, max2 = 0;
    ll cnt = 0, s = 0;
    for(int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        s += d(y, g, c);
        if(c[y] >= max) {
            max = c[y];
            maxp = i;
        }
        if(c[y] < min) min = c[y];
    }
    c[x] = max + 1;
    for(int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if(i == maxp) continue;
        if(c[y] >= max2) {
            max2 = c[y];
        }
    }
    if(g[x].size() >= 2) return w[x] = s + max2 + 1;
    return w[x] = s + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<vector<int> > g(n + 1, vector<int>());
        vector<int> c(n + 1);
        for(int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            g[x].push_back(i);
        }
        cout << d(1, g, c) << '\n';
        for(int i = 1; i <= n; i++) {
            cout << w[i] << " ";
        }
        cout << '\n';
        for(int i = 1; i <= n; i++) {
            cout << c[i] << " ";
        }
        cout << '\n';
        
    }
    
    return 0;
}
