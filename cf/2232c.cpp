#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
	    int n, t, s;
	    cin >> n >> t >> s;
	    
	    string u;
	    cin >> u;
	    
	    int l = 0, r = 0, ans = 0;
	    for(int i = 0; i < n; i++) {
	        if(u[i] == 'E') {
	            if(r * s == ans) continue;
	            ans++;
	            if(l * s < ans) l++;
	        }
	        else if(u[i] == 'I') {
	            if(l >= t) continue;
	            ans++;
	            l++;
	            r = min(r+1, t);
	        }
	        else {
	            if((long long) t * s == (long long)ans) continue;
	            ans++;
	            if(l * s < ans) l++;
	            r = min(r+1, t);
	        }
	        
	    }
	    
	    cout << ans << '\n';
	}
	
    return 0;
}
