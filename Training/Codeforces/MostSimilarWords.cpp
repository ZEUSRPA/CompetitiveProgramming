#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<string> words(n);
        for(int i=0;i<n;++i){
            cin>>words[i];
        }
        int minimo=INT_MAX;
        for(int i=0;i<words.size()-1;++i){
            for(int j=i+1;j<words.size();++j){
                int current=0;
                for(int k=0;k<words[i].size();++k){
                    current+=abs(words[i][k]-words[j][k]);

                }
                minimo=min(minimo,current);
            }
        }
        cout<<minimo<<ENDL;
    }
    return 0;
}