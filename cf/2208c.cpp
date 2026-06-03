#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    std::cout << std::fixed << std::setprecision(10);
    while(T--) {
        int n;
        cin >> n;
        vector<int> c(n), p(n);
        vector<double> a(n + 1);
        for(int i = 0; i < n; i++) {
            cin >> c[i] >> p[i];
        }
        for(int i = n - 1; i >= 0; i--) {
               a[i] = max(a[i+1], a[i+1] * (1-p[i]/100.0) + c[i]);
        }
        cout << a[0] << '\n';
    }
    
    
    return 0;
}
