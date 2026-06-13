#include <bits/stdc++.h>
using namespace std;
 
#define MOD 998244353
 
typedef long long ll;
 
struct ab {
    ll x;
    int idx;
};
 
inline bool cmp(const ab a, const ab b) {
    return (a.x > b.x) || (a.x == b.x && a.idx > b.idx); 
}
 
void update(int idx, int x, vector<ll> &v) {
    while(idx < v.size()) {
        v[idx] += x;
        idx = idx + (idx & -idx);
    }   
}
 
int query(int s, int e, vector<ll> &v) {
    int sum1 = 0, sum2 = 0;
    s--;
    while(s > 0) {
        sum1 += v[s];
        s = s - (s & -s);
    }
    
    while(e > 0) {
        sum2 += v[e];
        e = e - (e & -e);
    }
    
    return sum2 - sum1;
}

ll cnt = 0;

void merge(int s, int e, vector<int> &a) {
    if(s >= e) return;
    int m = (s+e)/2;
    merge(s, m, a);
    merge(m + 1, e, a);
    vector<int> tmp;
    int i = s, j = m + 1;
    while(i <= m && j <= e) {
        if(a[i] <= a[j]) {
            tmp.push_back(a[i]);
            i++;
        }
        else {
            tmp.push_back(a[j]);
            j++;
            cnt += m - i + 1;    
        }
    }
    while(i <= m) tmp.push_back(a[i++]);
    while(j <= e) tmp.push_back(a[j++]);
    for(int i = s; i <= e; i++) {
        a[i] = tmp[i - s];
    }
}

ll power(ll x, int exp) {
    ll res = 1;
    while(exp > 0) {
        if(exp % 2 == 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        
        exp /= 2;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        vector<ab> c;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                c.push_back((ab){(ll)a[i]*b[j], i + 1});
            }
        }
        
        sort(c.begin(), c.end(), cmp);
        
        vector<ll> v(n + 1);
        ll inv = 0;
        
        for(int i = 0; i < c.size(); i++) {
            inv += query(1, c[i].idx - 1, v);
            update(c[i].idx, 1, v);
        }
        merge(0, n - 1, a);
        inv -= (n * cnt) % MOD;
        cnt = 0;
        ll d = n * (n-1);
        ll mzd = power(d, MOD-2);
        cout << ((inv%MOD) * mzd) % MOD << '\n';
    }
    
    return 0;
}
