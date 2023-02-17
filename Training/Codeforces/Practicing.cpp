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

    //insert(x) -> insertar el elemento
    //find(x) -> pos del elemto || set.last() si no esta
    //size() -> cantidad de elemntos que hay en el set
    // un set mantiene un conjunto de elementos unicos
    // Nota: los sets y los mapas son funciones hash
    
    priority_queue<int,vector<int>,greater<int>> aux;
    int n,x;
    cin>>n;


    for(int i=0;i<n;++i){
         cin>>x;
         aux.push(x);
    }

    while(aux.size()){
        cout<<aux.top()<<ENDL;
        aux.pop();
    }
    

    //map[x]=3 -> para acceder a un elemento del mapa 
    //res.count(x)->verificar si existe el elemento 
     


    //map<char,int> -> tablas hash
    //set<int> -> elementos unicos
    //stack<int>
    //queue<int>
    //deque<int> -> insertar y sacar elementos desde ambos extremos
    //priority_queue<int> -> heap
    //vector<int> -> arreglo chido
    //pair<int,char> -> pares de datos


    return 0;
}

