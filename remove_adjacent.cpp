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

int n,cnt=0;
string str;
bitset<101> rem;

bool good(int ind){
	int p1=ind;
	while (--p1>=0){
		if (rem[p1]) continue;
		if (str[p1]-str[ind]==-1)
			return true;
		else break;
	}
	p1=ind;
	while (++p1<n){
		if (rem[p1]) continue;
		if (str[p1]-str[ind]==-1)
			return true;
		else break;
	}
	//cout<<'h'<<'\n';
	return false;
}

int main(){
	upgrade();
	cin>>n>>str;
	per(c,'a','z'+1){
		rep(i,0,n){
			//DEBUG(cnt);
			if (str[i]==c && good(i) &&!rem[i]){
				rem[i]=1;
				cnt++;
				//i-=2;
			}
		}
		per(i,0,n){
			//DEBUG(cnt);
			if (str[i]==c && good(i) &&!rem[i]){
				rem[i]=1;
				cnt++;
				//i-=2;
			}
		}
	}	
	cout<<cnt<<'\n';
}