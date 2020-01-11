#include <iostream>

using namespace std;
const int n = 10;
int a[n] = {10, 100, 20, 1, 2, 50, 70, 80, 3, 60};
int s[n];
void DP(){	
	//Khoi tao
	s[0] = 1;	
	//C[i]: do dai max tai a[i]
	for(int i = 1; i < n; i++){
		s[i] = 1;
		for(int j = i - 1; j >= 0; j--){
			if(a[j] <= a[i] && s[i] < s[j] + 1)s[i] = s[j] + 1;			
		}
	}
	
	for(int i = 0; i < n; i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	
	
	//Truy hoi
	int id = 0;
	int max = s[0];	
	for(int i = 1; i < n; i++){
		if(max < s[i]){
			max = s[i];
			id = i;
		}
	}	
	int seq[n], nb = 0;
	seq[nb++] = a[id];
	while(max > 1){
		max--;
		for(int j = id - 1; j >= 0; j--){
			if(s[j] == max && a[j] <= a[id]){
				id = j;
				seq[nb++] = a[id];
				break;
			}
		}
	}
	for(int i = nb - 1; i >=0 ; i--)cout<<seq[i]<<" ";
	cout<<" - Do dai: "<<nb;
}

int main(){
	DP();
	return 0;
}
