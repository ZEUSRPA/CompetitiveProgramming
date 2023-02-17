#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int travel=0;
    int p=0;
    int aux;
    int refills=0;
    while(dist){
        if(dist-travel<=tank){
            return refills;
        }
        while(p<stops.size()){
            if(stops[p]-travel<=tank){
                aux=p;
            }
            p++;
        }
        if(stops[aux]!=travel){
            refills++;
            p=aux;
            travel=stops[aux];
        }else{
            break;
        }
    }
    return -1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
