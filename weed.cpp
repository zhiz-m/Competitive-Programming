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

char a[1001][1001];
int n,m;
bool grow(int i, int j){
	//int u,d,l,r;
	if (i<0 || i>=n || j<0 || j>=m || a[i][j]=='X') return 0;
	//if(a[i][j]=='X') return 0;
	int cnt=0;
	cnt+=(((i==0)?   '.':a[i-1][j])=='X');
	cnt+=(((i==n-1)? '.':a[i+1][j])=='X');
	cnt+=(((j==0)?   '.':a[i][j-1])=='X');
	cnt+=(((j==m-1)? '.':a[i][j+1])=='X');
	
	return cnt>=2;
}

void recur(int i, int j){
	if (grow(i,j)){
		a[i][j]='X';
		recur(i-1,j);
		recur(i+1,j);
		recur(i,j-1);
		recur(i,j+1);
	}
}

int main(){
	upgrade();
	cin>>n>>m;
	rep(i,0,n){
		rep(j,0,m){
			cin>>a[i][j];
			//DEBUG(a[n][m]);
		}
		//cin.ignore(INT_MAX,'\n');
	}
	rep(i,0,n){
		rep(j,0,m){
			//DEBUG(a[i][j]);
			recur(i,j);
		}
	}
	int cnt=0;
	rep(i,0,n){
		rep(j,0,m){
			//DEBUG(a[i][j]);
			cnt+=(a[i][j]=='X');
			
		}
	}
	cout<<cnt<<'\n';
}