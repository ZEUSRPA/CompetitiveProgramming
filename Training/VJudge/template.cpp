#include <bits/stdc++.h>
#define ENDL '\n'
typedef long long int lli;

using namespace std;


//set<type>
//unordered_map<type1,type2>
//queue<type>
//stack<type>
//priority_queue<type>
void ans1(string str, int k) {
    unordered_map<char, int> chars;
    if (str.size()%k == 0) {
        for (int i = 0; i < str.length(); i++) {
            if(chars.count(str[i])) {
                chars[str[i]]++;
            } else {
                chars[str[i]] = 1;
            }
        }
        string base = "";
        bool was_broken =false;
        for (auto val : chars) {
         if (val.second%k == 0) {
             for (int i = 0; i < val.second/k; i++) {
                 base += val.first;
             }
         } else {
             cout<<"-1"<<ENDL;
             return;
         }
        }
        string solve = "";
        for (int i =0; i < k; i++) {
            solve += base;
        }
        cout<<solve<<ENDL;
    } else {
        cout<<"-1"<<ENDL;
    }
}

void ans(unordered_map <string, int> &database, string name) {
    if (database.count(name)) {
       database[name]++;
       name = name + to_string(database[name]);
       cout <<name<<ENDL;
    } else {
        database[name] = 0;
        cout <<"OK"<< ENDL;
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin>>k;
    string str;
    cin>>str;
    ans1(str, k);
    return 0;
}

