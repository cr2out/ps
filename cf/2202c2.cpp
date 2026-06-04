#include <bits/stdc++.h>
using namespace std;

struct pii {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        vector<long long> d(n + 1);
        stack<pii> st;
        for(int i = n; i >= 1; i--) {
            while(!st.empty()) {
                pii p = st.top();
                if(a[i] + 1 == p.x) {
                    d[n-i+1] -= n - p.y + 1; 
                    st.pop();
                }
                else break;
            }
            st.push({a[i], i});
            d[n-i+1] += n - i + 1;
        }
        for(int i = 2; i <= n; i++) {
            d[i] += d[i-1];
        }
        
        for(int i = 2; i <= n; i++) {
            d[i] += d[i-1];
        }
        cout << d[n] << '\n';
    }

}
