#include <bits/stdc++.h>

using namespace std;

long long int MaxPairwiseProduct(vector<long long int>& numbers) {
    sort(numbers.begin(),numbers.end());
    return numbers[numbers.size()-1] * numbers[numbers.size()-2];
}

int main() {
    int n;
    cin >> n;
    vector<long long int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
