#include<bits/stdc++.h>
using namespace std;

void setupIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main() {
    setupIO();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int ans = -1;
        for(char ch: s){
            ans = max(ans, ch-'a'+1);
        }

        cout << ans << '\n';
    }
    
    
    return 0;
}