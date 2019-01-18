#include <iostream>
#include <cmath> 
#include <fstream>
#include <cstdlib>

using namespace std;

int main ()
{
	//declare variables
	string memberType="";
	string borrowType="";
	const int TESTCASENUM = 9;
	
	ifstream fin("library_requests.txt");
	ofstream fout ("library_results.txt");
	
	//test for input file presence and proper open
	if (!fin)
	{
		cout << "file not found";
		system("PAUSE");
		return EXIT_FAILURE;
	}
	
	//while there is data for iteration...
	while (fin >> memberType >> borrowType)
	{
	
	if (memberType=="staff")
	{
		fout << "Staff may borrow ";
		
		if(borrowType=="books")
		{
			fout << "books for an entire term, in unlimited quantity" <<endl;
		}
	
		if (borrowType=="journals")
		{
			fout << "journals for two weeks, in unlimited quantity" <<endl;
		}
		
		if (borrowType=="electronic")
		{
		  fout <<"electronic without time limits, in unlimited quantity" <<endl;
		}
	}
	
	if (memberType=="student")
	{
		fout << "Students may borrow ";
		
		if (borrowType=="books")
		{
			fout << "books for 2 weeks, in unlimited quantity" <<endl;
		}
		
		if (borrowType=="journals")
		{
			fout << "journals for 2 weeks, in unlimited quantity" <<endl;
		}
		
		if (borrowType=="electronic")
		{
			fout << "electronic with time limits, in unlimited quantity" <<endl;
		}
	}
		
	if (memberType=="alumni")
	{
		fout <<"Alumni may borrow ";
		
		if (borrowType=="books")
		{
			fout << "books for 2 weeks, up to 20 books" <<endl;
		}
		
		if (borrowType=="journals")
		{
			fout << "journals under no circumstance" <<endl;
		}
		
		if (borrowType=="electronic")
		{
			fout << "electronic under no circumstance" <<endl;
		}
		
		
	}
	}//end while
	
	fin.close();
	fout.close();	
	system("PAUSE");
	return EXIT_SUCCESS;
}//end main

/*
TEST INPUT FILE (.txt file) DATA:
staff books
staff journals
staff electronic
student books
student journals
student electronic
alumni books
alumni journals
alumni electronic

TEST OUTPUT FILE RESULTS:
staff may borrow books for an entire term, in unlimited quantity
staff may borrow journals for two weeks, in unlimited quantity
staff may borrow electronic without time limits, in unlimited quantity
students may borrow books for 2 weeks, in unlimited quantity
students may borrow journals for 2 weeks, in unlimited quantity
students may borrow electronic with time limits, in unlimited quantity
alumni may borrow books for 2 weeks, up to 20 books
alumni may borrow journals under no circumstance
alumni may borrow electronic under no circumstance
*/
