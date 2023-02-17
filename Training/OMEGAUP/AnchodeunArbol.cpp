#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;



int computeNodesLeft(vector<pair<int,int>>& tree,int p,vector<pair<int,int>>& corners,int lvl,int current){
    int total=0;
    int aux;
    if(tree[p].second!=-1){
        aux=computeNodesLeft(tree,tree[p].second,corners,lvl+1,current);
        current+=aux;
        total+=aux;  
    }
    if(corners[lvl].first==0){
        corners[lvl].first=-1*(current);
    }
    corners[lvl].first=min(corners[lvl].first,-1*(current));
    if(corners[lvl].second==0){
        corners[lvl].second=-1*(current);
    }
    corners[lvl].second=max(corners[lvl].second,-1*(current));
    if(tree[p].first!=-1){
        total+=computeNodesLeft(tree,tree[p].first,corners,lvl+1,current+1);
    }
    return total+1;
}

int computeNodesRight(vector<pair<int,int>>& tree,int p,vector<pair<int,int>>& corners,int lvl,int current){
    int total=0;
    int aux;
    if(tree[p].first!=-1){
        aux=computeNodesRight(tree,tree[p].first,corners,lvl+1,current);
        current+=aux;
        total+=aux;
    }
    if(corners[lvl].first==0){
        corners[lvl].first=current;
    }
    corners[lvl].first=min(corners[lvl].first,(current));
    if(corners[lvl].second==0){
        corners[lvl].second=current;
    }
    corners[lvl].second=max(corners[lvl].second,(current));
    if(tree[p].second!=-1){
        total+=computeNodesRight(tree,tree[p].second,corners,lvl+1,current+1);
    }
    return total+1;
}

pair<int,int> getMaxWidth(vector<pair<int,int>>& corners){
    int i=2;
    pair<int,int> answer={1,1};
    while(i<corners.size()){
        if(corners[i].first==0){
            break;
        }
        int aux=abs(corners[i].first-corners[i].second)+1;
        if(aux>answer.second){
            answer.second=aux;
            answer.first=i;
        }
        i++;
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,p;

    cin>>n;
    vector<pair<int,int>> tree(n+1);
    vector<pair<int,int>> corners(n+1,{0,0});
    for(int i=1;i<=n;++i){
        cin>>p;
        cin>>tree[p].first;
        cin>>tree[p].second;
    }
    if(tree[1].first!=-1){
        computeNodesLeft(tree,tree[1].first,corners,2,1);
    }
    if(tree[1].second!=-1){
        computeNodesRight(tree,tree[1].second,corners,2,1);
    }
    auto answer=getMaxWidth(corners);
    cout<<answer.first<<" "<<answer.second<<ENDL;
    return 0;
}