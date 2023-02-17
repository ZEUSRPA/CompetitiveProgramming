#include <bits/stdc++.h>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using namespace std;

void max_sliding_window_naive(vector<int> const & A, int w) {
    // for (size_t i = 0; i < A.size() - w + 1; ++i) {
    //     int window_max = A.at(i);
    //     for (size_t j = i + 1; j < i + w; ++j)
    //         window_max = max(window_max, A.at(j));

    //     cout << window_max << " ";
    // }
    
    int m=0;
    vector<int> aux;
    for(int i=0;i<w;++i){

        if(aux.size()&&A[i]>aux.back()){
            for(auto &x:aux){
                x=A[i];
            }
        }
        aux.push_back(A[i]);
    }
    
    
    for(int i=w;i<A.size();++i){
        cout<<aux.front()<<" ";
        aux.erase(aux.begin());
        if(A[i]>aux.back()){
            for(auto &x:aux){
                x=max(x,A[i]);
            }
        }
        aux.push_back(A[i]);
    }
    cout<<aux.front()<<endl;

    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
