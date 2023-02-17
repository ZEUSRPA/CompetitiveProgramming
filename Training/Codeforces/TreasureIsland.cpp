#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;

vector<string> island;
vector<vector<int>> dp;
lli tot=0,may=0;
lli n,m;

bool isValid(lli x,lli y){
    if(x<n&&y<m){
        return island[x][y]!='#';
    }else{
        return false;
    }
}
bool walkRigth(lli x,lli y){
    bool aux=false;
    if(dp[x][y]!=-1){
        return dp[x][y]==1;
    }
    if((x+1==n-1&&y==m-1)){
        island[x][y]='#';
        return true;
    }else if((x==n-1&&y+1==m-1)){
        island[x][y]='#';
        return true;
    }
    if(isValid(x+1,y)){
        aux=walkRigth(x+1,y);
        if(aux){
            if(x!=0||y!=0){
                dp[x][y]=1;
                island[x][y]='#';
            }
            return true;
        }
    }
    if(isValid(x,y+1)){
        aux=walkRigth(x,y+1);
        if(aux){
            if(x!=0||y!=0){
                dp[x][y]=1;
                island[x][y]='#';
            }
            return true;
        }
    }
    dp[x][y]=aux;
    return aux;
}

bool walkDown(lli x,lli y){
    bool aux=false;
    if(dp[x][y]!=-1){
        return dp[x][y]==1;
    }
    if((x+1==n-1&&y==m-1)){
        island[x][y]='#';
        return true;
    }else if((x==n-1&&y+1==m-1)){
        island[x][y]='#';
        return true;
    }
    if(isValid(x,y+1)){
        aux=walkDown(x,y+1);
        if(aux){
            if(x!=0||y!=0){
                dp[x][y]=1;
                island[x][y]='#';
            }
            return true;
        }
    }
    if(isValid(x+1,y)){
        aux=walkDown(x+1,y);
        if(aux){
            if(x!=0||y!=0){
                dp[x][y]=1;
                island[x][y]='#';
            }
            return true;
        }
    }
    
    dp[x][y]=aux;
    return aux;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    dp.resize(n);
    for(int i=0;i<n;i++){
        dp[i]=vector<int>(m,-1);
    }
    island.resize(n);
    for(lli i=0;i<n;i++){
        cin>>island[i];
    }
    int tot=0;
    if(walkRigth(0,0)){
        tot++;
    }
    if(walkDown(0,0)){
        tot++;
    }
    cout<<tot<<ENDL;
    return 0;
}