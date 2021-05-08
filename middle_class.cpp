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
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
void upgrade(){ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);}

int main(){
	upgrade();
	int t;cin>>t;
	rep(zz,0,t){
		int n,x;cin>>n>>x;
		int input;
		VI neg;
		ll pos=0;
		ll ans=0;
		rep(i,0,n){
			cin>>input;
			if (input-x>0){
				pos+=input-x;
				ans++;
			}
			else{
				neg.pb(input-x);
			}
		}
		//DEBUG(ans);
		sort(all(neg));
		per(i,0,SZ(neg)){
			if (neg[i]+pos>=0){
				ans++;
				pos+=(ll)neg[i];
				//DEBUG(neg[i]);
			}
		}
		cout<<ans<<'\n';
	}
}