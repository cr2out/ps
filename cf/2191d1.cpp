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
        string s;
        cin >> s;
        s = " " + s;
        vector<int> a(n + 1), mi(n + 1), o(n + 1);
        for(int i = 1; i <= n; i++) {
            a[i] = a[i-1] + ((s[i]=='(')?1:-1);
            o[i] = o[i-1] + ((s[i]=='(')?1:0);
        }
        int p = 1, m = -1, su = 0;
        for(int i = 1; i <= n; i++) {
            while((i >= p || s[p] == ')') && p <= n) p++;
            if(p > n) break;
            if(s[i] == '(') continue;
            if(-a[p-1]+a[i-1] <= 0) m = max(m, i+n-p+(-a[p-1]+a[i-1])-(a[n]-(-a[p-1]+a[i-1])));
            else if(-a[p-1]+a[i-1] < o[n] - o[p-1]) m = max(m, i+n-p-(a[n]-a[p-1]+a[i-1]));
        }
        cout << m << '\n';
    }

    return 0;
}
