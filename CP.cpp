#include<bits/stdc++.h>
using namespace std;

void setupIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}


vector<bool> isPrime(int n) {
vector<bool> allPrime(n + 1, true);
    allPrime[0] = allPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (allPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                allPrime[j] = false;
            }
        }
    }
    return allPrime;
}

int largestPrime(int n) {
    vector<bool> allPrime = isPrime(n);
    int ans = 0;
    long long temp = 0;
    for(int i=2; i<=n; i++){
        if(allPrime[i]){
            long long sum = temp + i;

            if (sum <= n && allPrime[sum]) {
                ans = sum;     
            }

            temp += i;
            if (temp > n) break;
            
        }
    }

    return ans;
        
}

int main() {
    setupIO();

    cout << largestPrime(15);
    
    
    return 0;
}