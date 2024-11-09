#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N;
        long long K;
        cin >> N >> K;

        long long totalWaterings = 0;

        for (int i = 0; i < N; ++i) {
            long long X, Y;
            cin >> X >> Y;
            long long cycles = K / X;
            long long remainingDays = K % X;
            
            long long waterings = cycles-0.5;
            if (remainingDays > 0) {
                waterings++;
            }
            
            totalWaterings += waterings;
        }

        cout << "Case " << t << ": " << totalWaterings << endl;
    }

    return 0;
}
