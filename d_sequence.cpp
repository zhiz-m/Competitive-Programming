#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while (t--){
		int n,m;cin>>n>>m;
		ll ans=1,i=1;
		for (;i<=30;i++){
			if (1<<i > n) break;
			ans = ans * (((1 << (i-1))+1)%m)%m;
		}
		ans = ans * ((n- (1 << (i-1)) +2)%m)%m;
		ans--;
		//ans=(ans-1)%m;
		//ans=max((ll)0,ans);
		if (ans<0) ans+=m;
		cout << ans<<'\n';
	}
}