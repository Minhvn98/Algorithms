#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void in(int a[], int n){
	for(int i = 0; i < n; i++)cout<<a[i]<<" ";
}

bool isSNT(int soA)
{
	if (soA < 2)
	{
		return false;
	}
	else if (soA>2)
	{
		if (soA % 2 == 0)
		{
			return false;
		}
		for (int i = 3; i < sqrt((float)soA); i += 2)
		{
			if (soA%i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

vector<int> Gr(int arrSNT[], int count,int x){
	vector<int> s;
	while(x > 0){		
		int k = count - 1;
		while(k >= 0){
			if(arrSNT[k] <= x)break;
			k--;
		}
		if(k == -1){
			s.clear();
			break;
		}		
		int rs = x / arrSNT[k];
		x = x % arrSNT[k];
		for(int j = 0; j < rs; j++)
			s.push_back(arrSNT[k]);
	}
	return s;
}

int main(){
	int n = 342;
	int arrSNT[n];
	arrSNT[0] = 2;
	int t = 3;
	int count = 1;
	while(t < n){		
		if(isSNT(t))arrSNT[count++] = t;
		t += 2;
	}
	
	in(arrSNT, count);
	cout<<endl;
	
	vector<int>s;
	s = Gr(arrSNT, count, n);
	
	for(int i = 0; i < s.size(); i++){
		cout<<s[i]<<" ";
	}
	
	return 0;
}
