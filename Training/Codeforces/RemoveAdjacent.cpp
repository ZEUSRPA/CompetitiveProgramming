#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;


int maxDelete(string s){
    int maxi=0;
    bool again=false;
    char aux='z';
    while(aux!='a'-1 && s.size()>1){
        again=false;
        if(s.size()> 1&& s[0]==aux){
            if(s[0]-1==s[1]){
                s.erase(s.begin());
                again=true;
                maxi+=1;
            }
        }
        for(int i=1;i<s.size()-1;i++){
            if(s.size()>1 && s[i]==aux){
                if(s[i]-1==s[i-1]||s[i]-1==s[i+1]){
                    s.erase(s.begin()+i);
                    i--;
                    again=true;
                    maxi+=1;
                }
            }
        }
        if(s.size()>1 && s[s.size()-1]==aux){
            if(s[s.size()-1]-1==s[s.size()-2]){
                s.erase(s.end()-1);
                maxi+=1;
                again=true;
            }
        }
        if(!again)
            aux--;
    }
    return maxi;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,cont=0;
    string s;
    cin>>n;
    cin>>s;
    cout<<maxDelete(s)<<ENDL;
    return 0;
}