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
int pre[201][200003];
//int suf[201][200003];

int main(){
	upgrade();
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		rep(i,1,n+1){
			cin>>a[i];
		}
		rep(i,1,201){
			pre[i][0]=0;
			//cout<<'h';
			rep(j,1,n+1){
				pre[i][j]=(a[j]==i)+pre[i][j-1];
				//if (i==1) DEBUG(pre[i][j]);
			}
		}/*
		per(i,1,201){
			suf[i][n+1]=0;
			per(j,1,n+1){
				suf[i][j]=(suf[i][j]==i)+suf[i][j+1];
			}
		}*/
		int p1=1,p2=n;
		int ans=0;
		rep(i,1,201){
			p1=1,p2=n;
			while(a[p1]!=i&&p1<p2)
				p1++;
			while(a[p2]!=i&&p1<p2)
				p2--;
			int cnt=1;
			while(p1<p2){
				int temp=0;
				if (p2-p1!=1)
				rep(j,1,201){
					temp=max(temp,pre[j][p2-1]-pre[j][p1]);
				}
				ans=max(ans,temp+cnt*2);
				//if (i==1){DEBUG(cnt);DEBUG(temp);}
				//if (i==1){DEBUG(p1);DEBUG(p2);}
				p1++;p2--;
				while(a[p1]!=i&&p1<p2){
					p1++;
					//if (i==1){DEBUG(a[p1]);}
				}
				while(a[p2]!=i&&p1<p2){
					p2--;
					//if (i==1){DEBUG(a[p2]);}
				}
				//if (i==1){DEBUG(p1);DEBUG(p2);}
				cnt++;
				//if (i==1){DEBUG(cnt);DEBUG(temp);}
			}
		}
		cout<<max(ans,1)<<nl;
	}
}