#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        multiset<int> ms, ms2;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ms.insert(x);
        }
        ms2 = ms;
        
        int s = 0, e = n - 1, r = 0;
        while(s <= e) {
            int mid = (s + e) / 2;
            int m = mid;
            while(m >= 0) {
                auto t1 = ms.lower_bound(m);
                auto t2 = ms.lower_bound(m * 2 + 1);
                if(t1 != ms.end() && *t1 == m) {
                    ms.erase(t1);
                    m--;
                }
                else if(t2 != ms.end() && *t2 > m * 2) {
                    ms.erase(t2);
                    m--;
                }
                else break;
            }
            if(m < 0) {
                s = mid + 1;
                r = mid;
            }
            else {
                e = mid - 1;
            }
            ms = ms2;
        }
        cout << r + 1 << '\n';
    }

}
