#include <iostream>
#include <vector>
using namespace std;

void in(int a[], int n){
	for(int i = 0; i < n; i++)cout<<a[i]<<" ";cout<<endl;
}

void in(vector<int> rs){
	for(int i = 0; i < rs.size() - 1; i++)cout<<rs[i]<<" + ";cout<<rs[rs.size() - 1];
}

vector<int> Gr(int n, int arrCP[], int t){
	vector<int> rs;
	
	while(n > 0){
		int k = t - 1;
		while(k >= 0){
			if(arrCP[k] <= n)break;
			k--;
		}
		if(k == -1){
			rs.clear();
			break;
		}
		else{
			int s = n / arrCP[k];
			n -=  s * arrCP[k];
			for(int i = 0; i < s; i++)
				rs.push_back(arrCP[k]);
		}		
	}
	
	return rs;
}

int main(){
	int n = 95;
	cout<<"Nhap n: ";cin>>n;
	int arrCP[n];
	vector<int> rs;
	int t = 0;
	while(true){
		int scp = (t + 1) * (t + 1);
		if(scp > n)break;
		else{
			arrCP[t] = scp;			
			t++;			
		}
	}
	cout<<"Mang SCP: ";in(arrCP, t);

	rs = Gr(n, arrCP, t);
	
	if(rs.size() != 0){
		cout<<n<<" = ";
		in(rs);
	}
	else{
		cout<<"no solution";
	}
	return 0;
}
