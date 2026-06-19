#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--) {
        int n, m, k;
        cin >> n >> m >> k;
        int gc = 0;
        
        vector<vector<int> > a(n, vector<int>(m)), s(n, vector<int>(m)), w(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char x;
                cin >> x;
                if(x == '#') a[i][j] = -1;
                else if(x == 'g') {
                    a[i][j] = 1;
                    gc++;
                }
            }
        }
    
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == 1) s[i][j]++;
                if(i >= 1) s[i][j] += s[i-1][j];
                if(j >= 1) s[i][j] += s[i][j-1];
                if(i >= 1 && j >= 1) s[i][j] -= s[i-1][j-1];
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                w[i][j] = s[min(i+k-1, n-1)][min(j+k-1, m-1)];
                if(i - k >= 0) w[i][j] -= s[i-k][min(j+k-1, m-1)];
                if(j - k >= 0) w[i][j] -= s[min(i+k-1, n-1)][j-k];
                if(i - k >= 0 && j - k >= 0) w[i][j] += s[i-k][j-k];
            }
        }
        
        int mx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] != 0) continue;
                if(gc - w[i][j] > mx) mx = gc - w[i][j];
            }
        }
        
        cout << mx << '\n';
    }
    
    
    return 0;
}
