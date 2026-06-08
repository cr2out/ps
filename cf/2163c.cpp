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
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        ll cnt = 0;
        
        vector<int> mia(n), maa(n), mib(n), mab(n);
        mia[0] = a[0], maa[0] = a[0];
        mib[n-1] = b[n-1], mab[n-1] = b[n-1];
        
        for(int i = 1; i < n; i++) {
            mia[i] = min(mia[i-1], a[i]);
            maa[i] = max(maa[i-1], a[i]);
            mib[n-i-1] = min(mib[n-i], b[n-i-1]);
            mab[n-i-1] = max(mab[n-i], b[n-i-1]);
        }
        
        for(int l = 1; l <= 2 * n; l++) {
            int s = l, e = 2 * n;
            while(s <= e) {
                int m = (s + e) / 2;
                int sb = 0, eb = n - 1;
                int flag = 0;
                while(sb <= eb) {
                    int mb = (sb + eb) / 2;
                    if(l <= mib[mb] && mab[mb] <= m) {
                        eb = mb;
                        if(sb == eb) {
                            flag = 1;
                            break;
                        }
                    }
                    else {
                        sb = mb + 1;
                    }
                }
                if(flag && l <= mia[sb] && maa[sb] <= m) {
                    e = m;
                    if(s == e) {
                        cnt += 2*n - s + 1;
                        break;
                    }
                }
                else {
                    s = m + 1;
                }
            }
        }
        cout << cnt << '\n';
    }
	
    return 0;
}
