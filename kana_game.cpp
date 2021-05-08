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
typedef vector<long long> VLL;
typedef pair<int,int> PII;
typedef pair<long long, long long> PLL;
typedef long long ll;
void upgrade(){ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);}

int main(){
	upgrade();
	int t;cin>>t;
	while(t--){
		int x,n,m;cin>>x>>n>>m;
		int suc=0;
		if (m*10>=x)suc=1;
		while (n--){
			x=x/2+10;
		}
		//DEBUG(x);
		if (m*10>=x)suc=1;
		cout<<(suc?"YES":"NO")<<nl;
	}
}