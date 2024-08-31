// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <iostream>
#define F first
#define S second
#define fore(i,a,b) for(long long i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define ALL(s) begin(s), end(s)
#define ALLR(s) rbegin(s), rend(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
using namespace std;
typedef long double ld;
typedef long long lli;

const lli MAXN = 1e6+10;
lli primes[MAXN];
lli maxpos=0;

lli criba[MAXN];


void sieve(){
	fore(i,2,MAXN){
		criba[i]=1;
	}
	criba[0]=0;
	criba[1]=0;
	for(lli i=2;i*i<MAXN;++i){
		if(criba[i]==1){
			for(lli j=i*i;j<MAXN;j+=i){
				//if(j<0)break;
				criba[j]=0;
			}
		}
	}
	
	fore(i,2,MAXN){
		if(criba[i]==1){
			primes[maxpos++]=i;
		}
	}
	
}

lli gans[MAXN];
lli aux[MAXN];

void fillRange(lli oril, lli orir){
	lli cpos = 0;
	fore(i,0,MAXN){
		gans[i]=-1;
	}
	
	
	fore(i,0,orir-oril+1){
		aux[i]=1;
	}
	lli l=oril;
	
	while(l<MAXN &&l<=orir){
		aux[l-oril]=criba[l];
		l++;
	}
	lli pos = 0;
	while(pos<maxpos){
		lli start = l/primes[pos];
		start = primes[pos]*start;
		if(l%primes[pos]){
			start+=primes[pos];
		}
		
		for(lli i=start;i<=orir;i+=primes[pos]){
			aux[i-oril]=0;
		}
		pos++;
	}
	fore(i,0,orir-oril+1){
		if(aux[i]==1){
			gans[cpos++]=i+oril;
		}
	}
}

int main() {_ 
    lli l,r;
    sieve();
    while(cin>>l>>r){
    	fillRange(l,r);
    	lli maxansfirst;
    	lli maxanssecond;
    	lli minansfirst;
    	lli minanssecond;
    	lli mind=1e9;
    	lli maxd = 0;
    	lli cpos=1;
    	while(cpos<MAXN && gans[cpos]!=-1){
    		lli diff=gans[cpos]-gans[cpos-1];
    		if(diff<mind){
    			mind=diff;
    			minansfirst = gans[cpos-1];
    			minanssecond = gans[cpos];
    		}
    		if(diff>maxd){
    			maxd=diff;
    			maxansfirst =gans[cpos-1];
    			maxanssecond=gans[cpos];
    		}
    		cpos++;
    	}
    	if(mind==1e9){
    		cout<<"There are no adjacent primes."<<ENDL;
    	}else{
    		cout<<minansfirst<<","<<minanssecond<<" are closest, "<<maxansfirst<<","<<maxanssecond<<" are most distant."<<ENDL;
    	}
    }
    return 0;
}
