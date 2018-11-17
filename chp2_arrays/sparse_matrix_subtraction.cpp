#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
	cout << "This program implement the subtraction of two sparse matrix using array" <<endl;
	int m{0};
	int n{0};
	cout << "Please enter the size of the sparse matrix"<<endl;
	cin >> m >> n;
	cout << "Now start generate the two matrix of " << m << " X " << n << " "<< endl;
	cout << "Now generat the first matrix A: "<< endl;
	int matrix_a[m][n]{0};
	
	for (auto &row: matrix_a){
		cout << "[ ";
		for(auto &col : row){
		int temp =(1+ rand()/((RAND_MAX+1u)/6));
		col = ((temp%2) ==0 ) ? 0: temp ;
		cout << col << " ";
		}
		cout << "] " << endl;
	}
	
	cout << "Now generat the first matrix B: "<< endl;
	int matrix_b[m][n]{0};
	
	for (auto &row: matrix_b){
		cout << "[ ";
		for(auto &col : row){
		int temp =(1+ rand()/((RAND_MAX+1u)/6));
		col = ((temp%2) ==0 ) ? 0: temp ;
		cout << col << " ";
		}
		cout << "] " << endl;
	}
	
	cout << "Now start representing the above sparse matrix using arrays"<< endl;
	vector<vector<int>  > array_sm_A;
	vector<int>           first_row_A{m,n,0};
	
	array_sm_A.push_back(first_row_A);
	int ia=0;
	
	for (auto & row: matrix_a){
		int ja=0;
		for (auto &col : row){
			if (col!=0){
				vector<int> temp_row{ia,ja,col};
				array_sm_A[0][2]+=1;
				array_sm_A.push_back(temp_row);
			}
			++ja;
		}
	    ++ia;
	}
	
	cout << "Sparse Matric A: "<< endl;
	for (auto &ele_row : array_sm_A){
		cout <<"[ ";
		for (auto &ele_col : ele_row ){
			cout << ele_col << " ";
		}
		cout << "]" << endl;;
	}
	
	//---------------------------------------------------------------------------
	
	vector<vector<int>  > array_sm_B;
	vector<int>           first_row_B{m,n,0};
	
	array_sm_B.push_back(first_row_B);
	int ib=0;
	
	for (auto & row: matrix_b){
		int jb=0;
		for (auto &col : row){
			if (col!=0){
				vector<int> temp_row{ib,jb,col};
				array_sm_B[0][2]+=1;
				array_sm_B.push_back(temp_row);
			}
			++jb;
		}
	    ++ib;
	}
	
	
	
	cout << "Sparse Matric B: "<< endl;
	for (auto &ele_row : array_sm_B){
		cout <<"[ ";
		for (auto &ele_col : ele_row ){
			cout << ele_col << " ";
		}
		cout << "]" << endl;
	}
	//-------------------------------------------------------------------------------------------------
	
	
	cout << "Now Conduct A-B directly: "<< endl;
	int matrix_c[m][n]{0};
	int ic = 0;
	
	
	for (auto &row : matrix_c){
		int jc =0;
		cout << "[ ";
		for (auto &col : row){
			col = matrix_a[ic][jc]- matrix_b[ic][jc];
			cout << col << ' ';
			++jc;
		}
		
		++ic;
		cout << "]";
		cout << endl;
	}
	
	cout << "Now conduct A-B on sparse matrix representation:" << endl;
	vector<vector<int>  > array_sm_C;
	/*
	ia = 0;
	ja = 0;
	ib = 0;
	jb = 0;
	ic = 0;
	jc = 0;
	*/
	
	auto p_sm_A = array_sm_A.begin();
	auto p_sm_B = array_sm_B.begin();
	
	++p_sm_A;
	++p_sm_B;
	
	vector<int> c_head{m,n,0};
	array_sm_C.push_back(c_head);
	
	while( (p_sm_A!= array_sm_A.end() ) && (p_sm_B != array_sm_B.end()   ) ){
		
		if ((*p_sm_A)[0] == (*p_sm_B)[0] ){
			if ( (*p_sm_A)[1] == (*p_sm_B)[1] ){
				int temp_val = (*p_sm_A)[2]- (*p_sm_B)[2];
				if (temp_val != 0){
				vector<int> temp{(*p_sm_A)[0], (*p_sm_A)[1], temp_val };
				array_sm_C.push_back(temp);
				}
				++p_sm_A;
				++p_sm_B;  //如果两个col相等，那么就相加，推入C里面
				
				
			}else{
				if ( (*p_sm_A)[1] > (*p_sm_B)[1] ){
					int temp_val = - (*p_sm_B)[2];
					vector<int> temp{(*p_sm_B)[0], (*p_sm_B)[1], temp_val };
					array_sm_C.push_back(temp);
					++p_sm_B; //如果B的col 比较小，则将B 变成负数，推入C里面
				}else{
					int temp_val = (*p_sm_A)[2];
					vector<int> temp{(*p_sm_A)[0], (*p_sm_A)[1], temp_val };
					array_sm_C.push_back(temp);
					++p_sm_A; //如果A 的col 比较小，则将A 直接推入C里面。
					
					
				}
			}
			
			
			
		}else{
			
			if ( (*p_sm_A)[0] > (*p_sm_B)[0] ) {
				int temp_val = - (*p_sm_B)[2];
				vector<int> temp{(*p_sm_B)[0], (*p_sm_B)[1], temp_val };
				array_sm_C.push_back(temp);
				++p_sm_B; //如果B的row 比较小，则将B 变成负数，推入C里面
				
			}else{
				int temp_val = (*p_sm_A)[2];
				vector<int> temp{(*p_sm_A)[0], (*p_sm_A)[1], temp_val };
				array_sm_C.push_back(temp);
				++p_sm_A; //如果A 的col 比较小，则将A 直接推入C里面。
				
			}
			
			
			
		}
		
		
		
		
		
		
		 
	
	}
	
	while (p_sm_A!= array_sm_A.end() ){
		int temp_val = (*p_sm_A)[2];
		vector<int> temp{(*p_sm_A)[0], (*p_sm_A)[1], temp_val };
		array_sm_C.push_back(temp);
		++p_sm_A; //如果A 比较长， 就把A 剩下的元素都推入C里面
		
	}
	
	while (p_sm_B!= array_sm_B.end() ){
		int temp_val = -(*p_sm_B)[2];
		vector<int> temp{(*p_sm_B)[0], (*p_sm_B)[1], temp_val };
		array_sm_C.push_back(temp);
		++p_sm_B; //如果B 比较长， 就把B 剩下的元素都推入C里面
		
	}
	
	array_sm_C[0][2]= array_sm_C.size()-1;
	
	cout << "Sparse Matric C: "<< endl;
	for (auto &ele_row : array_sm_C){
		cout <<"[ ";
		for (auto &ele_col : ele_row ){
			cout << ele_col << " ";
		}
		cout << "]" << endl;
	}
	
	
	return 0;
}
