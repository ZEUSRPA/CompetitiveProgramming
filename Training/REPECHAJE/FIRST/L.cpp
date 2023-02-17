#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int q,last=-2;
    cin>>s;
    cin>>q;
    stack<int> p;
    stack<pair<char,unordered_set<int>>> pp;
    map<char,set<int>> letters;
    for(int i=0;i<s.size();i++){
        letters[s[i]].insert(i);
    }
    string aux;
    char b;
    bool found;
    while(q--){
        cin>>aux;
        if(aux=="push"){
            cin>>b;
            unordered_set<int> del;
            if(letters.count(b)){
                if(p.empty()||p.top()!=-1){
                    found=false;
                    for(auto &x:letters[b]){
                        if(x>last){
                            last=x;
                            found=true;
                            p.push(x);
                            del.insert(x);
                            pp.push(make_pair(b,del));
                            letters[b].erase(x);
                            break;
                        }else{
                            del.insert(x);
                            letters[b].erase(x);
                        }
                    }
                    if(!found){
                        p.push(-1);
                        last=-1;
                        pp.push(make_pair(b,del));
                    }

                }else{
                    p.push(-1);
                    pp.push(make_pair(b,del));
                    last=-1;
                }
                
            }else{
                p.push(-1);
                pp.push(make_pair(b,del));
                last=-1;
            }
            
        }else{
            if(!pp.empty()){
                auto z=pp.top();
                for(auto x:z.second){
                    letters[z.first].insert(x);
                }
                pp.pop();
            }
            p.pop();
            if(p.empty()){
                last=-2;
            }else{
                last=p.top();
                
            }
        }
        if(last!=-1){
            cout<<"YES"<<ENDL;
        }else{
            cout<<"NO"<<ENDL;
        }
    }
    return 0;
}