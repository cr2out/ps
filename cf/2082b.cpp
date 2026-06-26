#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int x, n, m;
        cin >> x >> n >> m;
        int y = x;
        for(int i = 0; i < m; i++) {
            if(y % 2 == 1) y = y / 2 + 1;
            else y /= 2;
            if(y <= 1) break;
        }
        for(int i = 0; i < n; i++) {
            y /= 2;
            if(y == 0) break;
        }
        cout << y << " ";
        y = x;        
        for(int i = 0; i < n; i++) {
            y /= 2;
            if(y == 0) break;
        }
        for(int i = 0; i < m; i++) {
            if(y % 2 == 1) y = y / 2 + 1;
            else y /= 2;
            if(y <= 1) break;
        }        
        cout << y << '\n';
    }
    return 0;
}
