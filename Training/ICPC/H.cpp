#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

vector<int> boxes;
int n,k;
int cont=0;

int combinations(lli a, lli b){
    sort(boxes.begin(),boxes.end());
    if(k<n){
        lli weight=0;
        for(int i=1;i;i++){
            for(int j=i+k-1;j<boxes.size();){
                if()
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli a,b;
    cin>>n>>k;
    boxes=vector<int> (n);
    for(int i=0;i<n;i++){
        cin>>boxes[i];
    }
    cin>>a>>b;
    cout<<combinations(a,b)<<ENDL;
    return 0;
}