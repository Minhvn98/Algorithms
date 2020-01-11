#include <iostream>

using namespace std;
//string Operator = "+-*/^";

int priority(char x)
{
	if(x == '+' || x == '-')return 1;
	if(x == '*' || x == '/')return 2;
	if(x == '^')return 3;
	return 0;
//	for(int i = 0; i < Operator.size(); i++)
//		if(x == Operator[i])
//			return i+1;
			
}

bool isOperator(char x){
	if(x == '+' || x == '-')return 1;
	if(x == '*' || x == '/')return 1;
	if(x == '^')return 1;
	return 0;
//	for(int i = 0; i < Operator.size(); i++)
//		if(x == Operator[i])
//			return true;
//	return false;
}

bool isOperand(char x){
	return (x >= 'a' && x <= 'z');
}

//void in(queue<char> q, stack<char> s){
//	cout<<"s: ";
//	int sizes = s.size();
//	for(int i = 0; i < sizes; i++){
//		char c = s.top();
//		cout<<c<<" ";
//		s.pop();
//	}
//	cout<<endl;
//	cout<<"q: ";
//	int sizeq = q.size();
//	for(int i = 0; i < sizeq; i++){
//		char c = q.front();
//		cout<<c<<" ";
//		q.pop();
//	}
//	cout<<endl;	
//}

void in(char q[], int n){
	for(int i = 0; i < n; i++){
		cout<<q[i];
	}	
}

void ToBalan(string f){
	int idq = -1;
	int ids = -1;
	char q[f.size()];
	char s[f.size()];
	
	for(int i = 0; i < f.size(); i++){	
		if(isOperand(f[i])){
			idq++;
			q[idq] = f[i];
		}
		else if(f[i] == '('){
			ids++;
			s[ids] = f[i];			
		}
		else if(f[i] == ')'){
			char c = s[ids];
			ids--;
			while(c != '('){
				idq++;
				q[idq] = c;				
				c = s[ids];
				ids--;
			}
		}
		else if(isOperator(f[i])){
			while(ids >= 0 && priority(f[i]) <= priority(s[ids])){
				char c = s[ids];
				idq++;
				q[idq] = c;				
				ids--;
			}
			ids++;
			s[ids] = f[i];
		}
//		in(s, ids + 1);
//		cout<<endl;
//		in(q, idq + 1);
//		cout<<endl;
	}
	in(q, idq + 1);
}

int main(){
	int t;
	cin>>t;
	string arrF[t];
	for(int i = 0; i < t; i++){
		fflush(stdin);
		getline(cin, arrF[i]);
	}
	for(int i = 0; i < t - 1; i++){
		ToBalan(arrF[i]);
		cout<<endl;
	}	
	ToBalan(arrF[t - 1]);
	return 0;
}
