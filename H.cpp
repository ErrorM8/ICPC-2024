#include <iostream>
#define MOD 998244353

using namespace std;
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        long long N, M, K;
        cin >> N >> M >> K;
        
        if (K == 1) {
            if (N * M > 1) {
                cout << 0 << endl; 
            } else {
                cout << 1 << endl; 
            }
            continue;
        }
        long long ways = (K * mod_exp(K - 1, N * M - 1, MOD)) % MOD;
        cout << ways << endl;
    }
}

int main() {
    solve();
    return 0;
}