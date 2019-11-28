#include "iostream"
#include "math.h"
#include "iomanip"

using namespace std;

struct process // Struct that contains our variables and functions
{
	int entry_matrix[5][5] = { 3,2,5,1,4, // Definition of enrty matrix.
					   6,2,1,0,7,
					   3,0,0,2,0,
					   1,1,3,2,2,
					   0,3,1,0,0};

	int core_matrix[5][5]; // Core matrix definition.

	int slide_amount;  

	int result_matrix[100][100] = {0}; // Definition of result matrix

	int core_size;

	int result_matrix_row;

	int result_matrix_col;

	bool func_controlof_process(double entry_matrix_col, double core_matrix_col, double slide_amount) { // Function for calculating the process can be operatable.
		float result_col_cal;

		result_col_cal = ((entry_matrix_col - core_matrix_col) / slide_amount + 1);
		
		if (fmod(result_col_cal,1) == 0) // If result of result column is integer, return false.
			return result_col_cal = false;
		else
		{
			return result_col_cal = true; // If column of result matrix isn't integer,  return true.
		}	
	}

	int funcof_result_col(int entry_matrix_col, int core_matrix_col, int slide_amount) { // function to calculate result matrix's column.
		int result_col_cal;

		result_col_cal = (entry_matrix_col - core_matrix_col) / slide_amount + 1;

		return result_col_cal;
	}

	int funcof_result_row(int entry_row, int core_row, int slide_amount) { // function to calculate result matrix's row.
		int result_row_cal;

		result_row_cal = (entry_row - core_row) / slide_amount + 1;
	
		return result_row_cal;
	}

};

int main()
{
	process process1; 

	int entry_matrix_size;

	bool operate;

	cout << "Enter the size of core matix : "; cin >> process1.core_size; // Getting the core size from user.

	cout << "\nEnter the slide amount: "; cin >> process1.slide_amount; // Getting the slide amount from user.

	entry_matrix_size = sizeof(process1.entry_matrix) / sizeof(process1.entry_matrix[0]); // calculating the size of entry matrix.

	operate = process1.func_controlof_process(entry_matrix_size, process1.core_size, process1.slide_amount); // Variable for deciding process can be operetable.



	if (operate == false) // If it is operetable : 
	{
		for (int i = 0; i < process1.core_size; i++) // Getting core matrix's elements from user.
		{
			for (int j = 0; j < process1.core_size; j++)
			{
				cout << "Enter the core matrix element [" << i + 1 << "][" << j + 1 << "] :";  cin >> process1.core_matrix[i][j];
			}
		}

		process1.result_matrix_row = process1.funcof_result_row(entry_matrix_size, process1.core_size, process1.slide_amount); //calculating result mmatrix row.

		process1.result_matrix_col = process1.funcof_result_col(entry_matrix_size, process1.core_size, process1.slide_amount); // calculating result matrix col.

		for (int i = 0; i <= (process1.result_matrix_row * process1.slide_amount) - process1.slide_amount; i +=process1.slide_amount) // For calculating the result matrix element by using core matrix and entyr matrix.
		{
			for (int j = 0; j <= (process1.result_matrix_col * process1.slide_amount) - process1.slide_amount; j +=process1.slide_amount)
			{
				for (int a = 0; a < process1.core_size; a++)
				{
					for (int b = 0; b < process1.core_size; b++)
					{
						process1.result_matrix[i][j] += process1.entry_matrix[i + a][j + b] * process1.core_matrix[a][b];
					}
				}
			}
		}

		cout << "********** - RESULT MATRIX - **********" << endl; 

		for (int i = 0; i < process1.result_matrix_row; i++) // for printing result matrix rows.
		{
			for (int j = 0; j < process1.result_matrix_col; j++) // for printing result matrix columns.
			{
				cout << setw(5) << process1.result_matrix[i][j] << setw(5);
			}
			cout << endl;
		}

	}

	else // If process can't operatable print an error message.
	{
		cout << "Can not operate ! ";
	}


	system("pause");
	return 0;

}