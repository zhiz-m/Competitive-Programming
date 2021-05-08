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
		string str;
		int n,a,b;cin>>n>>a>>b;
		int cnt=0;
		int c=a-b+1;
		int f=0;
		rep(i,0,n){
			if (b==1)
				str.pb('a');
			else if (f==0){
				str.pb('a');
				cnt++;
				if (cnt==c){
					cnt=0;
					f++;
				}
			}
			else {
				str.pb('a'+f);
				f++;
				if (f==b){
					f=0;
				}
			}
		}
		cout<<str<<nl;
	}
}