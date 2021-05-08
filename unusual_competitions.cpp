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
	int n;cin>>n;
	string str;cin>>str;
	int c1=0,c2=0;
	int ans=0,pre=0;
	rep(i,0,n){
		if (str[i]==')')c1++;
		else c2++;
		if (c1>c2||pre){
			ans++;
		}
		pre=c1>c2;
	}
	//DEBUG(c1);
	//DEBUG(c2);
	cout<<((c1==c2)?ans:-1)<<'\n';
}