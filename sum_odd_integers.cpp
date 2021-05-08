#include <bits/stdc++.h>

using namespace std;

int main(){
	long long t,n,k,ps;
	cin >>t;
	for (int aa=0;aa<t;aa++){
		cin >> n >> k;
		ps = n-k*k;
		if (ps >=0 && !(ps&1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}