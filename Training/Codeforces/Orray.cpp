#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
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

int main()
{
    IO;
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> aux(n);
        int current=0;
        int index=0;

        FOR(i,0,n){
            cin>>aux[i];
            if(aux[i]>current){
                current=aux[i];
                index=i;
            }
        }
        swap(aux[index],aux[0]);
        index=1;
        FORN(i,32,0){
            int maximo=INT_MIN;
            int maxindex=index;
            if((current&(1<<i))==0){
                FOR(j,index,n){
                    if((aux[j]&(1<<i))!=0 && (aux[j]|current)>maximo){
                        maximo=(aux[j]|current);
                        maxindex=j;
                    }
                }

            }
            if(maximo==INT_MIN){
                continue;
            }
            current=(current|aux[maxindex]);
            swap(aux[index],aux[maxindex]);
            index++;
        }
        FOR(i,0,n-1){
            cout<<aux[i]<<" ";
        }
        cout<<aux[n-1]<<ENDL;
    }
    return 0;
}