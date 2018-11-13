#include<iostream>
#include<vector>

using namespace std;

int main(){
	int m; 
	int n; /* the size of the matrix*/
	int row_min{10}; /*Minimum value in each row*/
	int pos_i;   /*Use for remember the position of the potential saddle point*/
	vector<int> pos_j;
	int j;
	
	
	cout << "Please Enter the M :";
	cin  >> m;
	cout << "Please Enter the N :";
	cin  >> n;
	
	cout << "Now generate the corresponding matrix of the specific size" << endl;
	
    int matrix[m][n];
	
	for (auto &row : matrix ){
		for(auto &col: row){
		     col =1 + rand() / ((RAND_MAX + 1U)/6);
		
		}
	
	}
	cout << "Genenration Finished"<<endl;
	cout << "The generated matrix is as followed" << endl;
	
	for (auto &row: matrix){
		cout << "[";
		for(auto &col: row){
			cout << col << " ";
		}
		cout <<  "]" << endl;
		
		
	}
	
	cout << "Now start to find the saddle points"<<endl;
	
	
	
    pos_i=0;	
	for (auto &row : matrix ){
		
        j    = 0;
		row_min  = 10;
		
		cout<<endl;
        cout<< "Now test row: " << pos_i << endl;
		
		
		for(auto &col: row){
			
			  cout<<"row_min @finding min: "<<row_min<<endl;
			  cout<<"col @finding min: "<< col <<endl;
			 
		     if(col< row_min){
				 row_min =col;
				 
				 while (!pos_j.empty() ){
					pos_j.pop_back();
				}

				 pos_j.push_back(j);
				 ++j;
				 continue;
			 }
			 
			 if(col == row_min){
				 pos_j.push_back(j);
			 }
			
			++j;
		
		}
		 cout<<endl;
		 cout<< "currently row_min: " << row_min << endl;

		 
		
		for (auto &pos_j_item :pos_j){
			cout << "Current point coordinate is" << '(' <<pos_i <<" " << pos_j_item << ")" <<endl;
			cout<< "Its value is :" << matrix[pos_i][pos_j_item] << endl;
			for (int i=0; i!=m; ++i){				
				cout << "currently matrix value:" <<  matrix[i][pos_j_item] << endl;
				if( (matrix[i][pos_j_item] > row_min) && (i!=pos_i)){
					pos_j_item = -1;
					cout<< "Exit Activated"<< endl;
					break;
				}
			}
		}
		
		
		for (auto pos_j_item : pos_j){
			if(pos_j_item != -1){
				cout<<"------------------------"<<endl;
				cout<< "The currently found saddle points is:"<<endl;
				cout<< pos_i<<" "<<pos_j_item<<endl;
				cout<<"------------------------"<<endl;
				
			}
		}


			
		
		
		++pos_i;
	
	}
	
	


	return 0;
}
