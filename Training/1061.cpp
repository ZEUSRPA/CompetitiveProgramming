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

string toString(vector<string> x){
    string aux;
    if(x.size()==0){
        aux="IMPOSSIBLE";
    }else{
        if(x.size()>1){
            aux+='{';
        }
        FOR(i,0,x.size()-1){
            aux+=x[i];
            aux+=", ";
        }
        aux+=x[x.size()-1];
        if(x.size()>1){
            aux+='}';
        }
    }
    return aux;
}

string getAns(string a, string b, string c){
    unordered_set<string> res;
    string q=c;
    string aux=b;
    b.pop_back();
    q.pop_back();
    if(q=="O"){
        if(b!="AB"&&b!="AB"){
            res.insert("O");
            res.insert("A");
            res.insert("B");
        }
    }else if(q=="A"){
        if(b=="A"||b=="AB"){
            res.insert("A");
            res.insert("B");
            res.insert("AB");
            res.insert("O");
        }else{
            res.insert("A");
            res.insert("AB");
        }
    }else if(q=="B"){
        if(b=="B"||b=="AB"){
            res.insert("A");
            res.insert("B");
            res.insert("AB");
            res.insert("O");
        }else{
            res.insert("B");
            res.insert("AB");
        }
    }else{
        if(b=="A"){
            res.insert("AB");
            res.insert("B");
        }else if(b=="B"){
            res.insert("AB");
            res.insert("A");
        }else if(b=="AB"){
            res.insert("AB");
            res.insert("A");
            res.insert("B");
        }
    }
    vector<string> fin;
    if(c[c.size()-1]=='+'&&aux[aux.size()-1]=='-'){
        for(auto x:res){
            x+='+';
            fin.push_back(x);
        }
    }else{
        for(auto x:res){
            x+='-';
            fin.push_back(x);
            x.pop_back();
            x+='+';
            fin.push_back(x);

        }
    }
    return toString(fin);
}

string getChild(string a,string b, string c){
    unordered_map<string,unordered_set<string>> abo;
    abo["A"].insert("AA");
    abo["AA"].insert("A");
    abo["A"].insert("AO");
    abo["AO"].insert("A");
    abo["AB"].insert("AB");
    abo["B"].insert("BB");
    abo["BB"].insert("B");
    abo["B"].insert("BO");
    abo["BO"].insert("B");
    abo["O"].insert("OO");
    abo["OO"].insert("O");
    unordered_set<string> res;
    unordered_set<char> dad;
    unordered_set<char> mom;
    string m=a;
    string d=b;
    m.pop_back();
    d.pop_back();
    for(auto x:abo[m]){
        for(auto z:x){
            mom.insert(z);
        }
    }
    for(auto x:abo[d]){
        for(auto z:x){
            dad.insert(z);
        }
    }
    
    for(auto x:dad){
        for(auto y:mom){
            string aux="";
            aux+=x;
            aux+=y;
            sort(aux.begin(),aux.end());
            for(auto z:abo[aux]){
                res.insert(z); 
            }
        }
    }

    vector<string> fin;
    if(a[a.size()-1]=='-'&&b[b.size()-1]=='-'){
        for(auto x:res){
            x+='-';
            fin.push_back(x);
        }
    }else{
        for(auto x:res){
            x+='-';
            fin.push_back(x);
            x.pop_back();
            x+='+';
            fin.push_back(x);

        }
    }
    return toString(fin);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a,b,c;
    int cont=1;
    while(cin>>a>>b>>c){
        if(a=="E"&&b=="N"&&c=="D"){
            break;
        }
        cout<<"Case "<<cont++<<": ";
        if(a=="?"){
            a=getAns(a,b,c);
        }else if(b=="?"){
            b=getAns(b,a,c);
        }else{
            c=getChild(a,b,c);
        }
        cout<<a<<" "<<b<<" "<<c<<ENDL;
    }
    return 0;
}