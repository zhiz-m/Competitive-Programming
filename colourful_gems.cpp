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

VLL v[3];
int s[3];
ll calc(ll a, ll b, ll c){
	return (a-b)*(a-b)+(b-c)*(b-c)+(a-c)*(a-c);
}

int main(){
	upgrade();
	int t;cin>>t;
	while(t--){
		rep(i,0,3)cin>>s[i];
		rep(i,0,3){
			v[i].resize(s[i],0);
			rep(j,0,s[i])cin>>v[i][j];
			sort(all(v[i]));
		}
		ll ans=LLONG_MAX;
		rep(a,0,3)
			rep(b,0,3)
				rep(c,0,3){
					if (a==b || b==c || a==c)continue;
					rep(i,0,s[a]){
						auto r=lower_bound(all(v[b]),v[a][i]);
						auto l=upper_bound(all(v[c]),v[a][i]);
						if (r!=v[b].end() && l!=v[c].begin())
						ans=min(ans,calc(v[a][i],*r,*(l-1)));
					}
				}
		cout<<ans<<nl;
	}
}