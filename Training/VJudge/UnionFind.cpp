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

int parent(vector<int> &numbers,int a){
    if(numbers[a]==a){
        return a;
    }else{
        numbers[a]=parent(numbers,numbers[a]);
    }
    return numbers[a];
}

void unir(vector<int> &numbers,vector<int> &height,int a,int b){
    int pa=parent(numbers,a);
    int pbb=parent(numbers,b);
    if(pa==pbb){
        return ;
    }
    if(height[pa]>=height[pbb]){
        numbers[pbb]=pa;
        if(height[pa]==height[pbb]){
            height[pa]++;
        }
    }else{
        numbers[pa]=pbb;
    }
}


bool same(vector<int> &numbers,int a ,int b){
    return parent(numbers,a)==parent(numbers,b);
}


int main()
{
    IO;
    int n,q,a,b;
    cin>>n>>q;
    vector<int> numbers(n);
    vector<int> height(n,1);
    for(int i=0;i<n;++i){
        numbers[i]=i;
    }
    char c;
    while(q--){
        cin>>c>>a>>b;
        if(c=='='){
            unir(numbers,height,a,b);
        }else{
            if(same(numbers,a,b)){
                cout<<"yes"<<ENDL;
            }else{
                cout<<"no"<<ENDL;
            }
        }
    }
    return 0;
}