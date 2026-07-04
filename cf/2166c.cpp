#include <bits/stdc++.h>

#define first f
#define second s;

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        set<pair<int, int> > pq;
        
        vector<int> back(n), next(n), c(n);
        
        back[0] = n-1;
        for(int i = 0; i < n - 1; i++) {
            pq.insert({max(a[i], a[i+1]), i});
            next[i] = i + 1;
            if(i != 0) back[i] = i-1;
        }
        next[n-1] = 0;
        pq.insert({max(a[n-1], a[0]), n-1});
        back[n-1] = n-2;
        ll cnt = 0;
        int j = 0;
        while(!pq.empty()) {
            auto [x, y] = *pq.begin();
            pq.erase(pq.begin());
            if(c[y]) continue;
            if(a[y] > a[next[y]]) {
                cnt += x;
                c[next[y]] = 1;
                next[y] = next[next[y]];
                back[next[y]] = y;
                pq.insert({max(a[y], a[next[y]]), y});
            }
            else {
                cnt += x;
                c[y] = 1;
                next[back[y]] = next[y];
                back[next[y]] = back[y];
                pq.insert({max(a[back[y]], a[next[y]]), back[y]});
            }
            j++;
            if(j == n - 1) break;
        }
        cout << cnt << '\n';
    }
    
    return 0;
}
