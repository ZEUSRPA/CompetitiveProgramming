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


struct Node{
    int val;
    Node* right;
    Node* left;
    Node(int x){
        val=x;
        right=nullptr;
        left=nullptr;
    }
};



void insert(Node* root,string path,int val){
    Node* aux=root; 
    for(int i=0;i<path.size();++i){
        if(path[i]=='R'){
            if(!aux->right){
                aux->right=new Node(0);
            }
            aux=aux->right;
        }else{
            if(!aux->left){
                aux->left=new Node(0);
            }
            aux=aux->left;
        }
    }
}

int diameter=0;
int getDiameter(Node* root){
    if(!root){
        return 0;
    }

    int l=getDiameter(root->left);
    int r=getDiameter(root->right);

    if(r+l+1>diameter){
        diameter=r+l+1;
    }
    return max(r,l)+1;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,x;
    cin>>t>>x;
    Node* root=new Node(x);
    t--;
    string path;
    while(t--){
        cin>>path>>x;
        insert(root,path,x);
    }
    getDiameter(root);
    cout<<diameter<<ENDL;
    return 0;
}

