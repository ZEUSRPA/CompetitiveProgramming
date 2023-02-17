#include <bits/stdc++.h>
#define ENDL '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,t,x;
    cin>>t;
    while(t--){
        cin>>n>>k;
        map<int,int> aux;
        for(int i=0;i<n;++i){
            cin>>x;
            aux[x]++;
        }
        int l=-1,r=-1,maximo=0,current=0;
        int auxl=-1,auxr=-1;
        int auxc=-1;
        for(auto y:aux){
            if(y.second>=k){
                if(y.first==auxc){
                    current++;
                }else{
                    if(current>maximo){
                        l=auxl;
                        r=auxr;
                        maximo=current;
                    }
                    current=1;
                }
                if(current==1){
                    auxl=y.first;
                    auxr=y.first;
                }else{
                    auxr=y.first;
                }
                auxc=y.first+1;
            }else{
                if(current>maximo){
                    l=auxl;
                    r=auxr;
                    maximo=current;
                }
                current=0;
            }
        }
        if(current>maximo){
            l=auxl;
            r=auxr;
            maximo=current;
        }
        if(maximo){
            cout<<l<<" "<<r<<ENDL;
        }else{
            cout<<-1<<ENDL;
        }

    }
    return 0;
}