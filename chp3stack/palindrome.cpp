#include<iostream>
#include<stack>
using namespace std;

int main(){
	cout<< "This program is used to judge whether an input string is palindrome or not."<<endl;
	cout << "Please input some string: " << endl;
	string input_str;
	cin >> input_str;
	stack<char> stack_str;
	string reverse_str;
	for (auto character : input_str){
		stack_str.push(character);
	}
	while(!stack_str.empty()){
		reverse_str +=stack_str.top();
		stack_str.pop();
		
	}
	cout<<"The reversed string is : " << reverse_str <<endl;
	
	if (input_str == reverse_str){
		cout<< "It is palindrome!"<<endl;
	}else{
		cout << "It is NOT palindrome" << endl;
	}
	
	return 0;
}
