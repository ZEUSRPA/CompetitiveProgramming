#include <iostream>

int fibonacci_sum_naive(long long n) {
    

    // long long previous = 0;
    // long long current  = 1;
    // long long sum      = 1;

    // for (long long i = 0; i < n - 1; ++i) {
    //     long long tmp_previous = previous;
    //     previous = current;
    //     current = tmp_previous + current;
    //     sum += current;
    // }

    // return sum % 10;
    long long int aux = n%60;
    if (aux <= 1)
        return aux;
    int prev=0;
    int current=1;
    int sum=1;
    for(int i=2;i<=aux;i++){
        int temp = prev;
        prev=current;
        current = (temp+current)%10;
        sum=(sum+current)%10;
    }

    return sum;

}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
