#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct point {
    int x, y;
};

inline bool cmp(const point a, const point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<point> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y;
        }
        sort(a.begin(), a.end(), cmp);
        vector<int> px, py, cy(n + 1);
        px.push_back(a[0].x);
        cy[a[0].y] = 1;
        for(int i = 1; i < n; i++) {
            if(a[i].x != a[i-1].x) px.push_back(a[i].x);
            cy[a[i].y] = 1;
        }
        for(int i = 1; i <= n; i++) {
            if(cy[i]) py.push_back(i);
        }
        vector<int> lmn(n), lmx(n), rmn(n), rmx(n);
        int j = 0;
        lmn[j] = lmx[j] = a[j].y;
        for(int i = 1; i < n; i++) {
            if(a[i].x != a[i-1].x) {
                j++;
                lmn[j] = lmn[j-1];
                lmx[j] = lmx[j-1];
            }
            lmn[j] = min(lmn[j], a[i].y);
            lmx[j] = max(lmx[j], a[i].y);
        }
        j = px.size()-1;
        rmn[j] = rmx[j] = a[n-1].y;
        for(int i = n-2; i >= 0; i--) {
            if(a[i].x != a[i+1].x) {
                j--;
                rmn[j] = rmn[j+1];
                rmx[j] = rmx[j+1];
            }
            rmn[j] = min(rmn[j], a[i].y);
            rmx[j] = max(rmx[j], a[i].y);
        }
        ll cnt = 0;
        for(int i = 0; i < px.size() - 1; i++) {
            int l = max(lmn[i]+1, rmn[i+1]+1);
            int r = min(lmx[i], rmx[i+1]);
            cnt += max((ll)(upper_bound(py.begin(), py.end(), r) - lower_bound(py.begin(), py.end(), l)), 0LL);
        }
        cout << cnt << '\n';
        
    } 
    return 0;
}
