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


lli solve(vector<lli> &presentsori){
    vector<lli> presents(presentsori);
    int index=0;
    FORN(i,64,0){
        lli maxElement=LLONG_MIN;
        lli maxIndex=index;
        FOR(j,index,presents.size()){
            if(((presents[j]&(1LL<<i))!=0)&&presents[j]>maxElement){
                maxElement=presents[j];
                maxIndex=j;
            }
        }
        if(maxElement==LLONG_MIN){
            continue;
        }

        swap(presents[index],presents[maxIndex]);
        swap(presentsori[index],presentsori[maxIndex]);
        maxIndex=index;

        FOR(j,0,presents.size()){
            if(j!=maxIndex&&((presents[j]&(1LL<<i))!=0)){
                presents[j]=presents[j]^presents[maxIndex];
            }
        }

        index++;
    }

    lli result=0;
    lli aux=0;
    FOR(i,0,index){
        result^=presentsori[i];
        cout<<presents[i]<<" "<<presentsori[i]<<ENDL;
    }
    cout<<result<<ENDL;
    FOR(i,index,presentsori.size()){
        cout<<presents[i]<<" "<<presentsori[i]<<ENDL;
        aux^=presentsori[i];
    }
    result+=aux;
    return result;

}

int main()
{
    IO;
    int n;
    cin>>n;
    vector<lli> presents(n);
    FOR(i,0,n){
        cin>>presents[i];
    }

    cout<<solve(presents)<<ENDL;


    return 0;
}