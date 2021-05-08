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
	VI fa;
	VI a(40002),b(40002);
	VI al(40002),bl(40002);
	int n,m,k;cin>>n>>m>>k;
	rep(i,1,n+1){
		cin>>a[i];
	}
	rep(i,1,m+1){
		cin>>b[i];
	}
	a[n+1]=b[m+1]=0;
	rep(i,1,40001){
		if(k%i==0){
			fa.pb(i);
			//DEBUG(i);
		}
	}
	int cnt=0;
	rep(i,1,n+2){
		if(a[i]==1) cnt++;
		else{
			al[cnt]++;
			cnt=0;
		}
	}
	rep(i,1,m+2){
		if(b[i]==1) cnt++;
		else{
			bl[cnt]++;
			cnt=0;
		}
	}
	ll ans=0;
	//DEBUG(SZ(fa));
	rep(i,1,40001){
		if (al[i]==0)continue;
		rep(j,1,40001){
			if(bl[j]==0) continue;
			int st=upper_bound(all(fa),i)-fa.begin()-1; // check lower bound upper bound
			//int st=lower_bound(all(fa),i)-fa.begin();
			//st=min(st,SZ(fa)-1);
			DEBUG(st);
			cnt++;
			while(st>=0){
				//DEBUG('h');
				int conj=k/fa[st];
				if (j>=conj){
					ans+=(ll)al[i]*bl[j]*(i-fa[st]+1)*(j-conj+1);
				}else break;
				st--;
			}
		}
	}
	DEBUG(cnt);
	cout<<ans<<'\n';
}