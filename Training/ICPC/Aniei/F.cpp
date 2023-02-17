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

vector<int> dsu;
vector<int> ranking;
int find(int n){
    if(dsu[n]==n){
        return n;
    }
    dsu[n]=find(dsu[n]);
    return dsu[n];
}

void une(int a,int b){
    int ap=find(a);
    int bp=find(b);
    if(ap==bp){
        return;
    }
    if(ranking[ap]>ranking[bp]){
        dsu[bp]=ap;
    }else{
        dsu[ap]=bp;
        if(ranking[ap]==ranking[bp]){
            ranking[bp]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,h,a,b;
    cin>>n>>h;
    dsu=vector<int>(n+1);
    ranking=vector<int> (n+1,1);
    for(int i=1;i<=n;++i){
        dsu[i]=i;
    }

    while(h--){
        cin>>a>>b;
        une(a,b);
    }
    unordered_set<int> res;
    int alone=0;
    for(int i=1;i<=n;++i){
        int rf=find(i);
        if(rf==i){
            if(ranking[i]==1){
                alone++;
            }else{
                res.insert(rf);
            }
        }else{
            res.insert(rf);
        }
    }
    cout<<res.size()<<" "<<alone<<ENDL;

    return 0;
}