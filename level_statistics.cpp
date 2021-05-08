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
		int n;cin>>n;
		int suc=1;
		int prev1=0,prev2=0;
		int p,c;
		//DEBUG(n);
		rep(i,0,n){
			cin>>p>>c;
			//DEBUG(p);
			//DEBUG(c);
			//DEBUG(prev1);
			//DEBUG(prev2);
			if (c>p || c<prev2 || p<prev1 || c-prev2>p-prev1){
				suc=0;
			}
			prev1=p,prev2=c;
		}
		cout<<((suc)?"YES":"NO")<<'\n';
	}
}