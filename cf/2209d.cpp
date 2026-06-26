#include <bits/stdc++.h>

using namespace std;

struct rgb {
    int n;
    char c;
    bool operator<(const rgb& other) const {
        return n < other.n;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        vector<rgb> a(3);
        int r, g, b;
        cin >> r >> g >> b;
        a[0] = {r, 'R'};
        a[1] = {g, 'G'};
        a[2] = {b, 'B'};
        string ans;
        sort(a.begin(), a.end());
        int d = a[2].n - a[0].n; 
        if(d < a[1].n) {
            for(int i = 0; i < d; i++) {
                ans += a[2].c;
                ans += a[1].c;
            }
            a[2].n -= d;
            a[1].n -= d;
            int d2 = a[1].n - (a[1].n/2);
            for(int i = 0; i < d2; i++) {
                ans += a[2].c;
                ans += a[1].c;
            }
            a[2].n -= d2;
            a[1].n -= d2;
            for(int i = 0; i < a[1].n; i++) {
                ans += a[0].c;
                ans += a[1].c;
            }
            a[0].n -= a[1].n;
            for(int i = 0; i < a[2].n; i++) {
                if(a[1].n != 0) {
                    ans += a[0].c;
                    ans += a[2].c;
                }
                else {
                    ans += a[2].c;
                    ans += a[0].c;
                }
            }
            if(a[0].n != a[2].n) ans = a[0].c + ans; 
        }
        else {
            for(int i = 0; i < a[1].n; i++) {
                ans += a[2].c;
                ans += a[1].c;
            }
            for(int i = 0; i < a[0].n; i++) {
                ans += a[2].c;
                ans += a[0].c;
            }
            if(a[2].n > a[1].n + a[0].n) ans += a[2].c;
        }
        cout << ans << '\n';
    }
    return 0;
}
