#include <iostream>
using namespace std;

int i0 = -1, j0 = -1;
long algo1(int a[], int n){
	long max = a[0];
	
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int s = 0;
			for(int k = i; k <= j; k++){
				s += a[k];				
			}
			if(max < s){
				max = s;
				i0 = i;
				j0 = j;
			}
		}
	}
	
	return max;
}

long algo1v2(int a[], int n){
	long best = a[0];
	for(int k = 1; k <= n; k++)
	for(int i = 0; i <= n - k; i++){
		int sum = a[i];
		for(int j = i+1; j < i + k; j++){
			sum += a[j];
			if(best < sum){
				best = sum;
				i0 = i;
				j0 = j;
			}
		}
	}
	
	return best;
}

long algo2(int a[], int n){
	long max = a[0];
	
	for(int i = 0; i < n; i++){
		int s = 0;
		for(int j = i; j < n; j++){			
			s += a[j];
			if(max < s){
				max = s;
				i0 = i;
				j0 = j;
			}
		}
	}
	
	return max;
}

int iL = -1, jL = -1;
long maxLeft(int a[], int i , int j){
	long maxL = a[j];
	int s = 0;
	for(int k = j; k >= i; k--){
		s += a[k];
		if(maxL > s){
			s = maxL;
			iL = i;
			jL = j;
			//cout<<"L: i: "<<iL<<" , j: "<<jL<<endl;
		}
		maxL = maxL > s ? maxL : s;
	}
	return maxL;
}

int iR = -1, jR = -1;
long maxRight(int a[], int i , int j){
	long maxR = a[i];
	int s = 0;
	for(int k = i; k <= j; k++){
		s += a[k];
		if(maxR > s){
			s = maxR;
			iR = i;
			jR = j;
			//cout<<"R: i: "<<iR<<" , j: "<<jR<<endl;
		}
	}
	return maxR;
}

long maxSeq(int a[], int i, int j){
	if(i == j ) return a[i];
	int m = (i+j)/2;
	
	//TH1
	long ml = maxSeq(a, i, m);
	
	//TH2
	long mr = maxSeq(a, m +1, j);
	long maxL = maxLeft(a, i ,m );
	
	//TH3
	long maxR = maxRight(a, m + 1, j);
	long maxLR = maxL + maxR;
	
	long max = ml;
	i0 = iL;
	j0 = jL;
	if(maxR > max){
		max = maxR;
		i0 = iR;
		j0 = jR;
	}
	
	if(maxLR > max){
		max = maxLR;
		i0 = iL;
		j0 = jR;
		//cout<<"i: "<<i0<<" , j: "<<j0<<endl;
	}
	return max;
}

long algo3(int a[], int n){
	return maxSeq(a, 0, n - 1);
}

long algo4(int a[], int n){
	long max = a[0];
	int s[n];
	s[0] = a[0];
	max = s[0];
	for(int i = 1; i < n ; i++){
		if(s[i-1] > 0)s[i] = s[i -1] + a[i];
		else s[i] = a[i];
		if(s[i] > max){
			max = s[i];
			j0 = i;
		}
	}
	int t = j0;
	while(true){		
		if(s[t - 1] <= 0 && j0 != 0)break;		
		t--;
	}
	i0 = t;
	return max;
}

int main(){
	int n = 6;
	cin>>n;
	int a[n];
	
	for(int i = 0; i < n; i++)
		cin>>a[i];
	
	cout<<"sum: "<<algo1(a, n);
	cout<<" , i: "<<i0<<" , j: "<<j0<<endl;
	
	cout<<endl;
	
	cout<<"sum: "<<algo1v2(a, n);
	cout<<" , i: "<<i0<<" , j: "<<j0<<endl;
	
	cout<<endl;
	
	cout<<"sum: "<<algo2(a, n);
	cout<<" , i: "<<i0<<" , j: "<<j0<<endl;
	
	cout<<endl;
	
	cout<<"sum: "<<algo3(a, n);
	
	cout<<endl;
	
	cout<<"sum: "<<algo4(a, n);
	cout<<" , i: "<<i0<<" , j: "<<j0<<endl;
	
	return 0;
}
//6 -2 11 -4 13 -5 2