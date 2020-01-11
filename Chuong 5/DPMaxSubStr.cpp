#include <iostream>

using namespace std;

void DP(int a[], int n, int s[]){
	s[0] = a[0];
	int index;
	int max = s[0];
	for(int i = 1; i < n; i++){
		if(s[i - 1] < 0)s[i] = a[i];
		else{
			s[i] = s[i-1] + a[i];
			if(max < s[i]){
				max = s[i];
				index = i;
			}
		}
	}	
	//cout<<"index: "<<index<<" = "<<s[index]<<endl;
	//Truy hoi
	while(s[index] != a[index]){
		cout<<a[index--]<<" ";
	}
	cout<<a[index];
	cout<<"\nTrong so: "<<max<<endl;
}

int main(){
	int n = 6;
	int a[n] = {-2, 11, -4, 13, -5, 2};
	int s[n];	
	DP(a, n, s);
	return 0;
}
