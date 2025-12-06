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
        string s;
        cin >> s;

        int ans=0;
        if(s[0]!='a') ans++;
        if(s[1]!='b') ans++;
        if(s[2]!='c') ans++;
        
        if(ans==3) cout << "NO";
        else cout << "YES";
        cout << '\n';
    }
    
    return 0;
}