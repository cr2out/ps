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
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<vector<int> > s(n + 1, vector<int>());
        for(int i = 0; i < n; i++) {
            vector<int> chk(n + 1);
            int mx = a[i], mn = a[i];
            chk[a[i]] = 1;
            for(int j = i+1; j < n; j++) {
                if(chk[a[j]]) break;
                chk[a[j]] = 1;
                mx = max(mx, a[j]);
                mn = min(mn, a[j]);
                if(mx - mn == j - i) s[j-i+1].push_back(mn);
            }
            s[1].push_back(a[i]);
        }
        
        int flag = 0;
        for(int i = n/2; i >= 1; i--) {
            /*
            cout << "l : " << i << '\n';
            for(int j = 0; j < s[i].size(); j++) {
                cout << s[i][j] << " ";
            }
            cout << '\n';
            */
            sort(s[i].begin(), s[i].end());
            for(int j = 0; j < s[i].size(); j++) {
                int p = lower_bound(s[i].begin()+j, s[i].end(), s[i][j]+i)-s[i].begin();
                if(p < s[i].size() && s[i][p]==s[i][j]+i) {
                    cout << i << '\n';
                    flag = 1;
                    break;
                }
                p = lower_bound(s[i].begin()+j, s[i].end(), s[i][j]-i)-s[i].begin();
                 if(p < s[i].size() && s[i][p]==s[i][j]-i) {
                    cout << i << '\n';
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag == 0) cout << "0\n";
    }
    
    return 0;
}
