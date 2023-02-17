#include <bits/stdc++.h>

long long get_fibonacci_huge_naive(long long n, long long m) {
    // if (n <= 1)
    //     return n;

    // long long previous = 0;
    // long long current  = 1;

    // for (long long i = 0; i < n - 1; ++i) {
    //     long long tmp_previous = previous;
    //     previous = current;
    //     current = tmp_previous + current;
    // }

    // return current % m;
    if(n<=1){
        return n;
    }
    std::vector<long long int> fibo;
    fibo.push_back(0);
    fibo .push_back(1);
    long long int secuence = 2;
    long long int j=1;
    while(true){
        fibo.push_back((fibo[j]+fibo[j-1])%m);
        secuence++;
        j++;
        if(fibo[j-1]==0&&fibo[j]==1){ 
            secuence-=2;
            break;
        }
        
    } 

    long long int prev=0;
    long long int current=1;
    long long aux = n% (secuence);
    for(int i=2;i<=aux;++i){
        long long int temp = prev;
        prev=current;
        current = (temp + current)%m;


    }
    return current;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
