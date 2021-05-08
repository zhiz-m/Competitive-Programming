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
	string str;
	int t;cin>>t;
	//cin.ignore(INT_MAX,'\n');
	rep(zz,0,t){
		cin>>str;
		int n=SZ(str);
		int prev=-1,mx=1;
		rep(i,0,n+1){
			if (i==n||str[i]=='R'){
				mx=max(mx,i-prev);
				prev=i;
			}
		}
		cout<<mx<<'\n';
	}
}