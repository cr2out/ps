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
	    
	    ll sum = 0;
	    for(int i = 0; i < n; i++) {
	        cin >> a[i];
	        sum += a[i];
	    }
	    
	    sort(a.begin(), a.end());
	    reverse(a.begin(), a.end());
	    
	    vector<ll> o;
	    int c = 1;
	    for(int i = 1; i < n; i++) {
	        if(a[i] == a[i-1]) {
	            c++;
	        }
	        else {
	            if(c % 2 == 1) {
	                o.push_back(a[i-1]);
	            }
	            c = 1;
	        }
	    }
	    if(c % 2 == 1) o.push_back(a[n-1]); 
	    
	    ll e = sum;
	    for(int i = 0; i < o.size(); i++) {
	        e -= o[i];
	    }
	    
	    ll o2 = 0;
	    for(int i = 0; i < o.size(); i++) {
	        if(o[i] < e) {
	            o2 = o[i];
	            break;
	        }
	    }
	    for(int i = 1; i < o.size(); i++) {
	        if(o[i-1] - o[i] < e) {
	            o2 = max(o2, o[i-1] + o[i]);
	            break;
	        }
	    }
	    
	    if(o2 == 0 && n - o.size() <= 2) {
	        e = 0;
	    } 
	    
	    cout << o2 + e << '\n';
	    
	}
	
    return 0;
}
