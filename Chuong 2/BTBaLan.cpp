#include <iostream>
#include <queue>
#include <stack>

using namespace std;
string Operator = "+-*/^";

int priority(char x)
{
	for(int i = 0; i < Operator.size(); i++)
		if(x == Operator[i])
			return i+1;
			
}

bool isOperator(char x){
	for(int i = 0; i < Operator.size(); i++)
		if(x == Operator[i])
			return true;
	return false;
}

bool isOperand(char x){
	return (x >= 'a' && x <= 'z');
}

void in(queue<char> q, stack<char> s){
	cout<<"s: ";
	int sizes = s.size();
	for(int i = 0; i < sizes; i++){
		char c = s.top();
		cout<<c<<" ";
		s.pop();
	}
	cout<<endl;
	cout<<"q: ";
	int sizeq = q.size();
	for(int i = 0; i < sizeq; i++){
		char c = q.front();
		cout<<c<<" ";
		q.pop();
	}
	cout<<endl;	
}

void in(queue<char> q){
	int sizeq = q.size();
	for(int i = 0; i < sizeq; i++){
		char c = q.front();
		cout<<c;
		q.pop();
	}	
}

void ToBalan(string f){
	queue<char> q; //Luu Toan hang
	stack<char> s; //Luu Toan tu
	for(int i = 0; i < f.size(); i++){	
		if(isOperand(f[i])){
			q.push(f[i]);
		}
		else if(f[i] == '('){
			s.push(f[i]);
		}
		else if(f[i] == ')'){
			char c = s.top();
			s.pop();
			while(c != '('){
				q.push(c);
				c = s.top();
				s.pop();
			}
		}
		else if(isOperator(f[i])){
			while(s.size() > 0 && priority(f[i]) <= priority(s.top())){
				char c = s.top();
				q.push(c);
				s.pop();
			}
			s.push(f[i]);
		}
		in(q, s);
	}
	//in(q);
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
