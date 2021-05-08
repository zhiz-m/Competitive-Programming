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

int a[200002];
vector<PII> v[201]; //block_num, length of block, index is num

PII b[200002]; //repeating number, len of block, index is block num;

int main(){
	upgrade();
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		rep(i,1,201){
			v[i]={};
		}
		a[0]=-1;
		rep(i,1,n+1){
			cin>>a[i];
		}
		a[n+1]=-1;
		//int prev=a[0];
		int cnt=1;
		int bcnt=0;
		int mx=0;
		//DEBUG('h');
		rep(i,1,n+1){
			if (a[i]==a[i-1]){
				cnt++;
			}
			else{
				bcnt++;
				if (i!=1){ 
					v[a[i-1]].pb(mp(bcnt,cnt));
					b[bcnt]=mp(a[i-1],cnt);
					mx=max(mx,cnt);
				}
				cnt=1;
			}
		}
		//DEBUG('h');
		int ans=0;
		rep(i,1,201){
			if(SZ(v[i])==0)continue;
			PII prev=v[i][0];
			//DEBUG('h');
			rep(j,1,SZ(v[i])){
				//DEBUG('b');
				if (v[i][j].fi-prev.fi==2){
					//DEBUG('a');
					int temp=min(v[i][j].se,prev.se)*2+b[prev.fi+1].se;
					ans=max(temp,ans);
				}
				prev=v[i][j];
			}
			//DEBUG('c');
		}
		//DEBUG('f');
		cout<<max(ans,cnt)<<nl;
	}
}