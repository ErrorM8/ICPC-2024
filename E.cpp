#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        long long N;
        int P;
        cin >> N >> P;

        if (N % 2 == 1 && P % 2 ==1) {

                cout << "Case " << i << ": Evenius" << endl;
            }
            else if(N % 2 == 0 && P % 2 == 0){
                cout << "Case " << i << ": Oddius" << endl;
            }
        
}
    return 0;
}
