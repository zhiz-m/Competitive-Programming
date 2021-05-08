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

int a[10][10];

void change(int i, int j){
	a[i][j]=(a[i][j]==1)?2:1;
}

int main(){
	upgrade();
	//int a[10][10];
	int t;cin>>t;
	while(t--){
		rep(i,1,10){//i goes down, j goes across
			string str;
			cin>>str;
			rep(j,1,10){
				a[i][j]=str[j-1]-48;
			}
		}
		//DEBUG(t);
		change(1,1);//
		change(4,2);
		change(7,3);
		change(2,4);//
		change(5,5);
		change(8,6);
		change(3,7);
		change(6,8);
		change(9,9);
		rep(i,1,10){//i goes down, j goes across
			rep(j,1,10){
				cout<<a[i][j];
			}
			cout<<nl;
		}
	}
}