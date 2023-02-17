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

Node* searchTree(Node* root, int val){
    Node* aux=root;
    while(aux!=nullptr){
        if(val==aux->val){
            return aux;
        }else if(val>aux->val){
            aux=aux->right;
        }else{
            aux=aux->left;
        }
    }
    return aux;
    
}

void insertTree(Node* root,int val){
    Node* aux=root;
    while(aux!=nullptr){
        if(val>aux->val){
            if(aux->right==nullptr){
                aux->right=new Node(val);
                break;
            }else{
                aux=aux->right;
            }
        }else{
            if(aux->left==nullptr){
                aux->left=new Node(val);
                break;
            }else{
                aux=aux->left;
            }
        }
    }
    
}

void preorder(Node* root){
    stack<Node*> next;
    next.push(root);
    while(next.size()){
        auto current=next.top();
        next.pop();
        cout<<current->val<<ENDL;
        if(current->right){
            next.push(current->right);
        }
        if(current->left){
            next.push(current->left);
        }

    }
}
void inorder(Node* root){
    if(!root)return;
    cout<<root->val;
    inorder(root->left);
    
    inorder(root->right);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    cin>>n;
    cin>>x;
    Node* root=new Node(x);
    for(int i=1;i<n;++i){
        cin>>x;
        insertTree(root,x);
    }
    int q;
    cin>>q;
    auto found=searchTree(root,q);
    if(found!=nullptr){
        preorder(found);
    }
    return 0;
}

