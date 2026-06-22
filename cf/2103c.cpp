#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), s(n), m1(n), m2(n), m3(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            a[i] = (a[i] > k) ? 1 : -1;
        }
        s[0] = a[0];
        for(int i = 1; i < n; i++) {
            s[i] = s[i-1] + a[i];
        }
        m1[n-2] = s[n-2];
        for(int i = n - 3; i >= 1; i--) {
            if(s[i] < m1[i+1]) m1[i] = s[i];
            else m1[i] = m1[i+1];
        }
        m2[1] = s[n-1] - s[0];
        for(int i = 2; i < n - 1; i++) {
            if(s[n-1] - s[i-1] < m2[i-1]) m2[i] = s[n-1] - s[i-1];
            else m2[i] = m2[i-1];
        }
        m3[n-1] = s[n-1] - s[n-2];
        for(int i = n - 2; i >= 2; i--) {
            if(s[n-1] - s[i-1] < m3[i+1]) m3[i] = s[n-1] - s[i-1];
            else m3[i] = m3[i+1];
        }

        int flag = 0;

        for(int i = 0; i < n - 2; i++) {
            if(s[i] > 0) continue;
            if(m3[i + 2] <= 0) {
                flag = 1;
                break;
            }
            if(m1[i + 1] - s[i] <= 0) {
                flag = 1;
                break;
            }
        }

        for(int i = n - 1; i >= 2; i--) {
            if(s[n-1] - s[i-1] > 0) continue;
            if(m2[i-1] - (s[n-1] - s[i-1]) <= 0) {
                flag = 1;
                break;
            }
        }

        if(flag) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }


    }
    return 0;
}
