#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	cout<< "This program delete duplicates in an array of 20 intergers."  << endl;
	cout<< "Now generate an array of 20 integers: " << endl;
	vector<int> array_A(20,0);
	cout << "[ ";
	for (auto &element : array_A){
		element = (1+ rand() / ((RAND_MAX + 1U)/6) );
		cout << element << " ";
	}
	
	cout << "] ";
	cout << endl;
	cout << "Now delete the duplicates using generic algorithm"<< endl;
	
	
	sort(array_A.begin(), array_A.end() );
	auto end_unique = unique(begin(array_A), end(array_A) );
	array_A.erase(end_unique, array_A.end());
	cout << "[ ";
	for (auto element : array_A){
		
		cout << element << " ";
	}
	
	cout << "] ";
	
	return 0;
}
