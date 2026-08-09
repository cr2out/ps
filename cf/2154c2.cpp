#include <bits/stdc++.h>
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
        int ef = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] % 2 == 0) ef = 1;
        }
        
        vector<pair<int, int> > p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i].first;
            p[i].second = a[i];
        }
        
        sort(p.begin(), p.end());
        
        int flag = 0;
        ll mn = 1e13;
        map<int, int> p1;
        for(int i = 0; i < n; i++) {
            for(int k = 2; k * k <= p[i].second; k++) {
                if(p[i].second % k == 0) {
                    p1[k]++;
                    if(k * k != p[i].second) p1[p[i].second / k]++;
                }
            }
            if(p[i].second != 1) p1[p[i].second]++;
        }
        
        for(auto it = p1.begin(); it != p1.end(); it++) {
            if(it->second >= 2) {
                flag = 1;
                break;
            }
        }
        
        if(flag) {
            cout << "0\n";
            continue;
        }
        
        for(int i = 1; i < n; i++) {
            for(int k = 2; k * k <= p[i].second; k++) {
                if(p[i].second % k == 0) {
                    mn = min(mn, (ll)(k - (p[0].second % k))*p[0].first);
                    int x = p[i].second / k;
                    mn = min(mn, (ll)(x - (p[0].second % x))*p[0].first);
                }
            }
            if(p[i].second != 1) mn = min(mn, (ll)(p[i].second - (p[0].second % p[i].second))*p[0].first);
        }
        
        
        if(ef == 1) {
            if(p[0].second % 2 == 1) {
                cout << p[0].first << '\n';
                continue;
            }
            cout << min(mn, (ll)p[1].first) << '\n';
            continue;
        }
        
        int same = 0;
        for(int i = 1; i < n; i++) {
            if(p[i].first != p[0].first) {  
                break;
            }
            same++;
        }
        
        map<int, int> p2, p3;
        
        for(int i = 0; i <= same; i++) {
            int t2 = p[i].second + 1;
            for(int k = 2; k * k <= t2; k++) {
                if(t2 % k == 0) {
                    p3[k]++;
                    if(k * k != t2) p3[t2 / k]++;
                }
            }
            p3[t2]++;
        }
        
        for(auto it = p1.begin(); it != p1.end(); it++) {
            if(p3[it->first] > 0) {
                mn = p[0].first;
                break;
            }
        }
        
        for(int i = 0; i < n; i++) {
            int t2 = p[i].second + 1;
            for(int k = 2; k * k <= t2; k++) {
                if(t2 % k == 0) {
                    if(p1[k] > 0 || p1[t2/k] > 0) {
                        mn = min(mn, (ll)p[i].first);
                    }
                }
            }
            if(p1[t2] > 0) mn = min(mn, (ll)p[i].first);
        }
        
        cout << min((ll)p[0].first + p[1].first, mn) << '\n';
    }

    return 0;
}
