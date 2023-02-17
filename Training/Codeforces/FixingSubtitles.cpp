#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,d;
    string r;
    string aux="";
    cin>>n>>r;
    for(auto x:r){
        if(x!='.'){
            aux+=x;
        }
    }
    d=stoi(aux);
    while(n--){
        cin>>aux;
        cout<<aux<<ENDL;
        vector<string> newTimes;
        for(int i=0;i<3;++i){
            cin>>aux;
            if(aux=="-->"){
                continue;
            }
            vector<int> time(4);
            string tmp="";
            int t=0;
            for(auto x:aux){
                if(x==':'||x==','){
                    time[t]=stoi(tmp);
                    tmp="";
                    t++;
                }else{
                    tmp+=x;
                }
            }
            time[t]=stoi(tmp);
            int miliseconds=time[0]*60*60*1000+time[1]*60*1000+time[2]*1000+time[3]+d;
            time[0]=miliseconds/3600000;
            miliseconds%=3600000;
            time[1]=miliseconds/60000;
            miliseconds%=60000;
            time[2]=miliseconds/1000;
            miliseconds%=1000;
            time[3]=miliseconds;
            tmp="";
            if(time[0]<10){
                tmp+='0';
            }
            tmp+=to_string(time[0])+':';
            if(time[1]<10){
                tmp+='0';
            }
            tmp+=to_string(time[1])+':';
            if(time[2]<10){
                tmp+='0';
            }
            tmp+=to_string(time[2])+',';
            if(time[3]<10){
                tmp+="00";
            }else if(time[3]<100){
                tmp+='0';
            }
            tmp+=to_string(time[3]);
            newTimes.push_back(tmp);

        }
        cout<<newTimes[0]+" --> "+newTimes[1]<<ENDL;
        cin.ignore();
        while(getline(cin,aux)){
            if(aux.size()==0){
                cout<<ENDL;
                break;
            }
            cout<<aux<<ENDL;
        }
    }
    return 0;
}

