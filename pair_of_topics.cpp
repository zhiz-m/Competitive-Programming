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

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll a[200001],input;
	VI pos,neg;
	int n;cin>>n;
	rep(i,0,n){
		cin>>a[i];
	}
	rep(i,0,n){
		cin>>input;
		input=a[i]-input;
		if (input>0) pos.pb(input);
		else neg.pb(input);
	}
	sort(all(pos));
	sort(all(neg),greater<int>());
	ll t=0,b=0,ans=(ll)SZ(pos)*(SZ(pos)-1)/2;
	//DEBUG(pos[1]);
	while(t<SZ(pos)&&b<SZ(neg)){
		//DEBUG(pos[t]);
		//DEBUG(neg[b]);
		if (pos[t]+neg[b]>0){
			ans++;b++;
		}else{
			t++;
			//DEBUG(ans);
			if (t<SZ(pos))
			ans+=b;
			//DEBUG(b);
			
		}
		if (b==SZ(neg)){
			ans+=b*(SZ(pos)-t-1);
			break;
		}
	}
	cout<<ans<<'\n';
}