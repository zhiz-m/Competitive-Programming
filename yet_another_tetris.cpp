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
	VI v(101);
	int t;cin>>t;
	//cout<<t<<'\n';
	//DEBUG(t);
	rep(zz,0,t){
		int mx=0;
		int n;cin>>n;
		//DEBUG(n);
		int suc=1;
		rep(i,1,n+1){
			cin>>v[i];
			mx=max(mx,v[i]);
			//DEBUG(v[i]);
		}
		rep(i,1,n+1){
			if ((mx-v[i])%2!=0)
				suc=0;
		}
		cout<<((suc)?"YES":"NO")<<'\n';
	}
	//cout<<'e'<<'\n';
}