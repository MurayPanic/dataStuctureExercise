#include<iostream>
using namespace std;



int fibo_search(int A[], int n, int key){
	int fiboMm2 = 1, fiboMm1 =1;
	int fiboM = fiboMm2 + fiboMm1;
	while (fiboM < n){
		fiboMm2 = fiboMm1;
		fiboMm1 = fiboM;
		fiboM = fiboMm2 + fiboMm1;
		
	}
	
	int offset = -1;
	
	
	while(fiboM > 1){
		int index = min(offset + fiboMm2, n-1);
		
		if(A[index]  < key){
			fiboM  = fiboMm1;
			fiboMm1 = fiboMm2;
			fiboMm2 = fiboM - fiboMm1;
			offset  = index;
		}
		else if(A[index]  > key){
			fiboM = fiboMm2;
			fiboMm1 = fiboMm1 - fiboMm2;
			fiboMm2 = fiboM - fiboMm1;
		}else{
			return index;
		}
		
	}
	
	if (fiboMm1 and A[offset +1]==key){
		return offset +1;
	}
	
	
	
	
	return -1;
	
	
	
	
	
}


int main(){
	
	int input_array[10] ={6,14,23,36,55,67,76,78,81,89};
	
	int result = fibo_search(input_array, 10, 78);
	cout << result << endl;
	
	
	return 0;
}
