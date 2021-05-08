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
	int t;cin>>t;
	while(t--){
		int a[200001];
		int n;cin>>n;
		rep(i,0,n){
			cin>>a[i];
		}
		sort(a,a+n);
		a[n]=-1;
		int mx=0;
		int cnt=1;
		int diff=0;
		rep(i,1,n+1){
			if (a[i]==a[i-1])cnt++;
			else{
				mx=max(mx,cnt);
				cnt=1;
				diff++;
			}
		}
		int ans;
		//DEBUG(mx);
		//DEBUG(diff);
		if (diff-1>=mx)
			ans=mx;
		else{
			ans=min(diff,mx-1);
		}
		cout<<ans<<nl;
	}
}