#include <iostream>

using namespace std;

int DC(int x, int n){
	if(n == 0)
		return 1;
	else{
		if(n % 2 != 0){
			return x * DC(x, n - 1);
		}
		else{
			int st = DC(x, n / 2);
			return st * st;
		}
	}
}

int main(){
	int x = 3;
	int n = 5;
	
	int rs = DC(x, n);
	cout<<rs;
	return 0;
}
#include<iostream>
using namespace std;


int pow(int x, int n){
    if(n == 0)
        return 1;
    if(n % 2 != 0)
        return x*pow(x,n-1);
    int st = pow(x,n/2);
    return st*st;
}

int power(int x, unsigned int y) 
{ 
    int temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y%2 == 0) 
        return temp*temp; 
    else
        return x*temp*temp; 
} 

// ham pow cho so thuc va mu am
float power(float x, int y)  
{  
    float temp;  
    if(y == 0)  
        return 1;  
    temp = power(x, y / 2);  
    if (y % 2 == 0)  
        return temp * temp;  
    else
    {  
        if(y > 0)  
            return x * temp * temp;  
        else
            return (temp * temp) / x;  
    }  
} 
 main(){
 	cout << power(2,3);
 }