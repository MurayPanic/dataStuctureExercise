#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(){
	
	cout << "This program apply find out the common element in two arrays and restored the elements" << endl;
	
	cout << "Now generate the first array A : " <<endl;
	
	vector<int>  array_A(25,0);
	
	cout << "[ ";
    for (auto &element : array_A ){
		
		element = 1 + (rand()/ ( (RAND_MAX + 1u) /6) );
		cout << element << " " ;
	}	
	cout << "] ";
	cout << endl;
	sort(array_A.begin(), array_A.end());
	
	cout << "Now generate the second array B: " <<endl;
	vector<int>  array_B(30,0);
	
	cout << "[ ";
    for (auto &element : array_B ){
		
		element = 1 + (rand()/ ( (RAND_MAX + 1u) /6) );
		cout << element << " " ;
	}	
	cout << "] ";
	sort(array_B.begin(), array_B.end());
	
	cout << "Now find out the common element of these two arrays and restored them in C:";
	
	vector<int> array_C;
	
	set_intersection(array_A.begin(), array_A.end(), array_B.begin(), array_B.end(), back_inserter(array_C));
	
	cout << endl;
	
	sort(array_C.begin(), array_C.end());
	auto end_unique=unique(array_C.begin(), array_C.end());
	array_C.erase(end_unique, array_C.end());
	
	cout << "[ ";
    for (auto element : array_C ){
		
		
		cout << element << " " ;
	}	
	cout << "] ";
	
	
	
	return 0;
}
