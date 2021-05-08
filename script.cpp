#include <bits/stdc++.h>

using namespace std;

const int n = 1000,m=1000;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//srand((unsigned)(time(0)));
	random_device rd;
	default_random_engine gen(rd());
	uniform_int_distribution<long long>dis(0,1);
	cout<<n<<" "<<m<<'\n';
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<((dis(gen))?'.':'X');
		}
		cout<<'\n';
	}
	//cout<<'\n';
}