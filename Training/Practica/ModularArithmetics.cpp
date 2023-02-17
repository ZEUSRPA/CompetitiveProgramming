//


//Bit manipulation
//
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

int bfs(vector<vector<int>> &graph,int f, int t) {
    queue<int> next;
    vector<int> visited;
    //O(1)
    //O(logn)
    map<int,bool> visited;
    int lvl=0;
    next.push(f);
    while(!q.emty()){
        auto aux=q.top();
        q.pop();
        visited[aux]=true;
        for(auto n:graph[aux]){
            if(n==t){
                return lvl;
            }else{
                if(visited.cout(n)==0){
                    next.push(n);
                }
            }
        }
    }

    while(!q.empty()){
        int current=q.size();
        while(current--){
            auto aux=q.top();
            q.pop();
            if(aux==t){
                return lvl;
            }
            for(auto x:graph[aux]){
                if(visited.count(x)==0){
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
        lvl++;
    }

    return -1;

}

// Tomorrow contest in codeforces.




int dfs(vector<vector<int>> &graph,int f, int t,int distance){
    if(f==t){
        return distance;
    }
    visited[f]=true;
    int res=INT_MAX;
    for(auto x:graph[f]){
        if(visited[x]==false){
            res=min(dfs(graph,x,t,distance+1),res);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> graph;
    map<map<int,int>> graph;
    graph[0][2]=3;
    graph[0][2]=5;


    //O(nlogn)
    //O(n)

    
    return 0;
}


