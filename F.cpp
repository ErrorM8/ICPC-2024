#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        long long s = (X + Y + Z);
        long long semi_perimeter = s / 2;
        long long A2 = semi_perimeter * (semi_perimeter - X) * (semi_perimeter - Y) * (semi_perimeter - Z);
        long long numerator = A2;
        long long denominator = semi_perimeter * semi_perimeter;
        long long g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
        
        cout << numerator << "/" << denominator << endl;
    }

    return 0;
}