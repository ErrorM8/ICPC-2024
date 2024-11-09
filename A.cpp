#include <iostream>
#include <vector>
using namespace std;
vector<int> generateGoodSequence(int n) {
    vector<int> sequence;
    int start = 5;  
    for (int i = 0; i < n; ++i) {
        sequence.push_back(start + (i % 10));  
    }
    return sequence;
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n;  
        vector<int> result = generateGoodSequence(n);
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
