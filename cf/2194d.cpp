#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > a(n, vector<int>(m));
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
                cnt += a[i][j];
            }
        }
        int f = cnt, mid = cnt / 2;
        cnt = 0;
        int x, y;
        int flag = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cnt += a[n-1-j][i];
                if(cnt >= mid) {
                    x = i;
                    y = j;
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        cout << (ll)mid * (f-mid) << '\n';
        for(int i = 0; i < x; i++) {
            cout << "R";
        }
        for(int i = 0; i < n - y - 1; i++) {
            cout << "D";
        }
        cout << "RD";
        for(int i = 0; i < y; i++) {
            cout << "D";
        }
        for(int i = 0; i < m - x - 1; i++) {
            cout << "R";
        }
        cout << '\n';
    }

    return 0;
}
