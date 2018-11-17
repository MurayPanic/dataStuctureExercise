#include<iostream>
#include<vector>
#include<map>
using namespace std;

void find_mode(vector<int> *array){
	map<int, int> freq_table;
	
	for (auto element: *array){
		auto dict_iter = freq_table.find(element);
		if( dict_iter != (freq_table.end())  ){
			 (dict_iter->second ) +=1; 
			
		}else{
			freq_table[element] = 1;
			
		}
	}
    
	int max_key ;
	int max_freq =0;
	
	for (auto item : freq_table){
		
		if (max_freq < item.second){
			max_freq = item.second;
			max_key = item.first;
		}else{
			if (max_freq == item.second){
				max_key = NULL;
				
			}
		}
		
		
	}
	
	if(max_key){
		cout << "The mode is " << max_key << endl;
		cout << "Its frequency is: " << max_freq << endl;
	
	}else{
		cout  << "There is no mode" <<endl;
	}
	
	
}

int main(){
	cout << "This program find the mode of the array" << endl;
	cout << "Please intput an array of numbers:" <<endl;
	vector<int> input_array;
	int n;
	while(cin >> n){
		input_array.push_back(n);
	}
	
	cout << "The input array is: "<< endl;
	cout <<"[ ";
	for (auto element : input_array){
		
		cout << element << " ";
	}
	cout << "]" << endl;
	
	find_mode( &input_array );
	
	return 0;
}
