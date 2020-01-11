#include<iostream>
#include<cmath>
using namespace std;
bool soNguyenTo(int soA) // h�m bool tr? v? true/false
{
	if (soA < 2) // N?u s? A nh? hon 2
	{
		return false;// tr? v? false
	}
	else if (soA>2)// N?u s? A l?n hon 2
	{
		if (soA % 2 == 0)  // X�t xem A c� chia h?t cho 2 kh�ng?
		{
			return false;// N?u chia h?t, return false.
		}
		for (int i = 3; i < sqrt((float)soA); i += 2)  // x�t t? 3 d?n can b?c 2 c?a s? A
		{
			if (soA%i == 0)  // n?u A chia h?t cho m?t s? n�o d� trong do?n n�y
			{
				return false;// tr? v? k?t qu? sai
			}
		}
	}
	return true;// sau t?t c? c�c ch? tr�n, n� m� kh�ng sai th� cu?i c�ng n� d�ng :3
}
void in(int a[],int n){
	for (int i=1;i<=n;i++)
		cout<<a[i]<<" + ";
	cout<<endl;
}
void quaylui(int a[],int t[],int n,int i){
	for (int j=a[i-1];j<=((n-t[i-1])/2);j++)
	{
		if (soNguyenTo(j))
		{
			a[i]=j;
			t[i]=t[i-1]+j;
			quaylui(a,t,n,i+1);	
		}
	}
	a[i]=(n-t[i-1]);
	if (soNguyenTo(a[i]))
		in(a,i);
}
int main(){
	int n = 33;
	//cin>>n;
	int a[n];
	int t[n];	
	t[0]=0;
	a[0]=1;
	quaylui(a,t,n,1);
	return 0;
}

