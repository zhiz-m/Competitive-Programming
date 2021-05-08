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
	ll a[300009],b[300009];
	int t;cin>>t;
	rep(zz,0,t){
		ll n;cin>>n;
		ll start;
		ll mx=LLONG_MAX;
		rep(i,0,n){
			cin>>a[i]>>b[i];
		}
		rep(i,0,n){
			ll prev=((i==0)?n-1:i-1);
			ll nex=((i==n-1)?0:i+1);
			ll eff = min(b[prev],a[i]);//min(b[i],a[nex]);//-a[i];//+a[prev];
			if (eff<mx){
				mx=eff;
				start=i;
			}
		}
		//DEBUG(start);
		//start=2;
		ll cost=0;
		ll cur=start;
		rep(zzz,0,n){
			if (cur>=n){
				cur-=n;
			}
			//DEBUG(cur);
			ll nex = (cur==n-1)?0:cur+1;
			cost+=max(0LL,a[cur]);
			//DEBUG(cost);
			a[nex]-=b[cur];
			cur=nex;
		}
		cout<<cost<<'\n';
		rep(i,0,n){
			a[i]=b[i]=0;
		}
	}
}