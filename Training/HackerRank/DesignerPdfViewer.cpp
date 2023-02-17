#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> heights(26);
    string word;
    int maxHeight=0;
    for(int i=0;i<26;i++){
        cin>>heights[i];
    }
    cin>>word;
    for(char x:word){
        if(heights[x-'a']>maxHeight){
            maxHeight=heights[x-'a'];
        }
    }
    cout<<word.size()*maxHeight<<ENDL;
    return 0;
}