#include <bits/stdc++.h>
#define pb push_back;
#define DEBUG(x) cerr<<'<'<<#x<<": "<<x<<'\n';

using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		/*
		if (n==1){
			cout << "BW";
			for (int i=2;i<m;i++){
				cout<<'B';
			}
		}*/
		{
			for (int i=0;i<n;i++){
				for (int j=0;j<m;j++){
					if (i==0&&j==0)
						cout<<'W';
					else
						cout<<'B';
				}
				cout<<'\n';
			}
		}
	}
}