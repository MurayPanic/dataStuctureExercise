#include<iostream>

using namespace std;

void merge_arrays(double (*a)[6], double (*b)[10], double (*c)[16]){
	auto ic = begin(*c);
	for (auto ia = begin(*a); ia!= end(*a); ++ia){
		*ic = *ia;
		++ic;
	}
	
	for (auto ib = begin(*b); ib!= end(*b); ++ib){
		*ic = *ib;
		++ic;
	}

}


int main(){
	cout << "This program includes a function merge_arrays."<< endl;
	cout << "Now generate the arrays for merging:"<< endl;
	
	const int asize = 6;
	const int bsize = 10;
	const int csize = asize + bsize;
	double (arrayA)[asize];
    double (arrayB)[bsize];
	double (arrayC)[csize]={0};
	double (*a)[asize] = &arrayA;
	double (*b)[bsize] = &arrayB;
	double (*c)[csize] = &arrayC;
	



    for (auto element : arrayA){
		
		element = 1 + rand()/( (RAND_MAX + 1u)/6);
		
	}
	

	
	for (auto element : arrayB){
		
		element = 1 + rand()/( (RAND_MAX + 1u)/6);
		
	}
	
	cout << "The generated arrayA is " << endl;
	cout <<"[ ";
    
    for (auto element : arrayA){
		cout << element  << " ";
	}	
	cout << "]" << endl;
	
	cout << "The generated arrayB is " << endl;
	cout <<"[ ";
    
    for (auto element : arrayB){
		cout << element  << " ";
	}	
	cout << "]" << endl;
	
	
	
	cout << "Now merge array A and B into a new Array C"<<endl;
	
	
	
	merge_arrays(a,b,c);
	
	
	cout << "The merged array is " << endl;
	cout << "[" ;
	
	for (auto element : arrayC){
		cout << element << " ";
	}
	
	cout << "]" << endl;
	
	
	return 0;

	
}
