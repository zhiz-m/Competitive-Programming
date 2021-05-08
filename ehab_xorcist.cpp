#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
#define SZ(x) (int)(x).size()
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=b-1;i>=a;i--)
#define DEBUG(x) cerr<<'<'<<#x<<": "<<x<<'\n'
#define nl '\n'
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
void upgrade(){ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);}

int main(){
	upgrade();
	ll u,v;cin>>u>>v;
	if (v<u || (v-u)%2==1){
		cout<<-1<<nl;
		return 0;
	}
	if (v==u){
		if (v==0)cout<<0<<nl;
		else{
			cout<<1<<nl;
			cout<<u<<nl;
		}
		return 0;
	}
	ll p=(v-u)/2;
	if ((p|u)!=p+u){
		cout<<3<<nl;
		cout<<p<<' '<<p<<' '<<u<<nl;
	}
	else{
		cout<<2<<nl;
		cout<<p+u<<' '<<p<<nl;
	}
}