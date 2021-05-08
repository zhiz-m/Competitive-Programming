#include <bits/stdc++.h>

using namespace std;

int arr[200001]={};
int arr2[26]={};
//int arr3[100]={};
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int zz;cin >> zz;
	while (zz--){
		int n,k,sum=0;
		char ch;
		cin >>n>>k;
		for (int i=0;i<n;i++){
			cin >>ch;
			arr[i]=ch-(int)'a';
			//cout << arr[i] << " ";
		}
		int mc1=0;//,mc2=0;
		//,n1,n2;
		for (int i=0;i<k;i++){
			fill_n(arr2,26,0);
			if (i>k-i-1) break;
			for (int j=i;j<n;j+=k){
				arr2[arr[j]]++;
			}
			if (i!=k-i-1){
				for (int j=k-i-1;j<n;j+=k){
					arr2[arr[j]]++;
				}
			}
			for (int j=0;j<26;j++){
				if (arr2[j]>=mc1){
					mc1=arr2[j];
					//n1=j;
				}
			}
			if (i==k-i-1)
				sum+=n/k-mc1;
			else{
				sum+=2*n/k-mc1;
			}
			mc1=0;
			//fill_n(arr2,100,0);
			//fill_n(arr3,100,0);
		}
		if (n==1) cout << 0 <<'\n';
		else cout << sum <<'\n';
	}
}