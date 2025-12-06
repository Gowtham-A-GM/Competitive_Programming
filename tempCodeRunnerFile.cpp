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

        int ans=0;
        if(n%2!=0){
            ans = 0;
        }
        else{
            int chicks = n/2;
            int cows = 0;

            while(chicks >= 0){
                if((n - chicks*2)%4 == 0){
                    ans++;
                }
                chicks--;
            }
        }
        cout << ans << '\n';
    }
    
    
    return 0;
}