#include <bits/stdc++.h>
using namespace std;

vector<int> type,colour;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int zzz;
	int n;
	int one_only=1;
	int f=1;
	int no_pair;
	int pair_index;
	cin >> zzz;
	while (zzz--){
		one_only=f=no_pair=1;
		cin >> n;
		type=colour=vector<int>(n,0);
		for (int i=0;i<n;i++){
			cin >> type[i];
			if (i>=1&&one_only&&type[i]!=type[i-1])
				one_only=0;
			if (i>=1&&no_pair&&type[i]==type[i-1]){
				pair_index=i-1;
				no_pair=0;
			}
		}
		if (no_pair && type[0]==type[n-1]){
			no_pair=0;
			pair_index=n-1;
		}
		//cout << ' ';
		if (one_only){
			cout << 1 << '\n';
			while (n--)
				cout << 1 << " ";
			cout << '\n';
		}
		else if (n%2==0){
			cout << 2 << '\n';
			for (int i=0;i<n;i+=2){
				cout << 1 << " " << 2 << " ";
			}
			cout << '\n';
		}
		else if (!no_pair){
			//cout << "pair" << pair_index<< " ";
			f=1;
			cout << 2 << '\n';
			for (int i=0;i<n;i++){
				cout << f << " ";
				if (i!=pair_index){
					if (f==1)
						f=2;
					else
						f=1;
				}
			}
			cout << '\n';
		}
		else {
			cout << 3 <<'\n';
			for (int i=0;i<n-1;i+=2){
				cout << 1 << " " << 2 << " ";
			}
			cout << 3 << '\n';
		}
	}
}