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
	int a[5001];
	int t;cin>>t;
	rep(zz,0,t){
		int n;cin>>n;
		rep(i,1,n+1){
			cin>>a[i];
		}
		int p1=1,p2=n,suc=0;
		while (p1!=n-1){
			while (p2!=p1+1){
				if (a[p1]==a[p2]){
					suc=1;
					break;
				}
				p2--;
			}
			p2=n;
			p1++;
		}
		puts((suc)?"YES":"NO");
	}
}