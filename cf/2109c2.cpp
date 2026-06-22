#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        ll n;
        cin >> n;
        cout << "mul 9" << endl;
        int ok;
        cin >> ok;
        cout << "digit" << endl;
        cin >> ok;
        cout << "digit" << endl;
        cin >> ok;
        cout << "add " << n - 9 << endl;
        cin >> ok;
        cout << "!" << endl;
        cin >> ok;
        if(ok == -1) break;
    }

    return 0;
}
