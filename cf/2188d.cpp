#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        ll x, y, p, q;
        cin >> x >> y;
        ll ad = x&y, st = 1;
        while(st * 2 <= ad) st *= 2;
        ll m = min(x,y);
        if(x > y) p = x, q = 0;
        else p = 0, q = y;
        
        ll tmp = st*2-(x&(st*2-1));
        if(tmp < m && ((x + tmp) & y) == 0) {
            m = tmp;
            p = x + m;
            q = y;
        }
        tmp = st*2-(y&(st*2-1));
        if(tmp < m && ((y + tmp) & x) == 0) {
            m = tmp;
            p = x;
            q = y + m;
        }
        
        ll xc = 0, yc = 0;
        ll t = 1;
        while(t < st) {
            if((y&t)!=0) xc+=t;
            if((x&t)!=0) yc+=t;
            t *= 2;
        }
        if((x&(st*2-1))-(st-1)+xc < m) {
            m = (x&(st*2-1))-(st-1)+xc;
            p = x - m;
            q = y;
        }
        if((y&(st*2-1))-(st-1)+yc < m) {
            m = (y&(st*2-1))-(st-1)+yc;
            p = x;
            q = y - m;
        }
        
        cout << p << " " << q << '\n';
    }

    return 0;
}
