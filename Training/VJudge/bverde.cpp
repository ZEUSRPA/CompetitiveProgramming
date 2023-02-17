#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

bool valid(vector<int> &books,int t,int b){
    for(int i=0;i<books.size()-b+1;++i){
        if(books[i+b-1]-(i>0?books[i-1]:0)<=t){
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,t;
    cin>>n>>t;
    vector<int> books(n);
    for(int i=0;i<n;++i){
        cin>>books[i];
        if(i){
            books[i]+=books[i-1];
        }
    }

    int l=0,r=n;
    int current=0;
    for(int p=n;p;p/=2){
        while(current+p<=n&&valid(books,t,current+p)){
            current+=p;
        }
    }
    cout<<current<<ENDL;

    return 0;
}