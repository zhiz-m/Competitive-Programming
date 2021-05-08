#include <bits/stdc++.h>
#define pb push_back;
#define DEBUG(x) cerr<<'<'<<#x<<": "<<x<<'\n';
using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	bool prep[100001];
	bool pren[100001];
	int a[100001];
	int b[100001];
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for (int i=0;i<n;i++){
			cin>>a[i];
		}
		for (int i=0;i<n;i++){
			cin>>b[i];
		}
		prep[0]=pren[0]=0;
		if (n>0){
			prep[1]=(a[0]==1);
			pren[1]=(a[0]==-1);
		}
		//DEBUG(pren[1]);
		for (int i=2;i<n;i++){
			prep[i]=((a[i-1]==1)||prep[i-1]);
			pren[i]=((a[i-1]==-1)||pren[i-1]);
			//DEBUG(a[i]);
			
		}
		int suc=a[0]==b[0];
		for (int i=n-1;i>=0;i--){
			if (a[i]>b[i] && !pren[i])
				suc=0;
			else if (a[i]<b[i] && !prep[i])
				suc=0;
			//DEBUG(pren[i]);
			//DEBUG(prep[i]);
		}
		cout<<(suc?"YES" : "NO")<<'\n';
	}
}