#include <iostream>
using namespace std;

float t = 6.0;
int count = 0;

void ina(int a[], int n, int t){
	cout<<"(((((6 ";
	for(int i = 1; i <= n; i++){		
		switch(a[i]){
			case 1:
				cout<<" + ";
				break;
			case 2:
				cout<<" - ";
				break;
			case 3:
				cout<<" * ";
				break;
			case 4:
				cout<<" / ";
				break;
		}
		cout<<"6)";
	}
	cout<<" = "<<t<<endl;
	count++;
}

void in(int a[], int n, int T){
	if(t == T)
		ina(a, n, T);
	else{
		int tmp = 6.0;
		for(int i = 1; i <= n; i++){
			switch(a[i]){
				case 1:
					tmp += 6;
					break;
				case 2:
					tmp -= 6;
					break;
				case 3:
					tmp *= 6;
					break;
				case 4:
					tmp /= 6;
					break;
			}
		}
		if(tmp == T){
			ina(a, n, T);			
		}			
	}
}

void BTKPhan(int a[], int n, int i, int T){	
	for(int j = 1; j <= 4; j++){
		a[i] = j;
		switch(j){
			case 1:
				t += 6.0;
				break;
			case 2:
				t -= 6.0;
				break;
			case 3:
				t *= 6.0;
				break;
			case 4:
				t /= 6.0;
				break;
		}
		
		if(i == n){
			in(a, n, T);
		}
		else BTKPhan(a, n, i + 1, T);
		switch(j){
			case 1:
				t -= 6.0;
				break;
			case 2:
				t += 6.0;
				break;
			case 3:
				t /= 6.0;
				break;
			case 4:
				t *= 6.0;
				break;
		}
	}
}

int main(){
	int n = 5;
	int T = 18;
	cin>>T;
	int a[n + 1];
	BTKPhan(a, n, 1, T);
	cout<<"So luong cau hinh: "<<count;
	return 0;
}
