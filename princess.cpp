	#include <bits/stdc++.h>

	using namespace std;

	int main(){
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		int t,n,k,c;
		unordered_set<int> done;
		int not_done;
		int need;
		int a[100001];
		int f;
		//int f;
		cin >> t;
		while (t--){
			done.clear();
			c=0;
			cin >> n;
			f=1;
			for (int j=1;j<=n;j++){
				cin >> k;
				//int test=k;
				//f=1;
				need=1;
				for (int i=0;i<k;i++){
					cin >> a[i];
				}
				for (int i=0;i<k;i++){
					if (!done.count(a[i])){
						done.insert(a[i]);
						c++;
						need=0;
						break;
					}
				}
				if (f&&need){
					not_done=j;
					f=0;
				}
				//cout <<test;
				//cout << "hi" <<endl;
			}
			//for (int i:done)cout << i;
			if (c==n)
				cout << "OPTIMAL" <<endl;
			else{
				for (int i=1;i<=n;i++){
					if (!done.count(i)){
						cout << "IMPROVE" << endl<< not_done << " " << i << endl;
						break;
					}
				}
			}
		}
	}