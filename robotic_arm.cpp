#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

using namespace std;

int main ()
{

	//declare variables, calculation tolerance
	double armLength = 0, xCoord = 0, yCoord = 0 ;
	int errorCount=0;
	const double TOL = 0.1;

	//fin is plain txt: 1 robotic arm legnth, and _ x,y coordinates the arm tries to reach
	ifstream fin("robotic_arm_inputs.txt");

	//test for input file presence and proper open
	if (!fin)
	{
		cout << "file not found";
		system("PAUSE");
		return EXIT_FAILURE;
	}

	//armLength is constant throughout, and is the first data piece in input file
	fin >> armLength;

	//while there is coordinate data to iterate...
	while (fin >> xCoord >> yCoord)
	{
		//hypotenuse of triange with a,b sides x-Coordinate, y-Coordinate is range of arm
		double range = sqrt((pow(xCoord,2))+(pow(yCoord,2))) ;

		//if arm is too short to reach coordinate...
		if (fabs(armLength-range)>TOL)
		{
			errorCount++;
			cout << "! (" << xCoord << ", " << yCoord << ") " << "is out of reach.";
		}
	}

	cout << "Times arm could not reach: " << errorCount << endl;

	system("PAUSE");
	return EXIT_SUCCESS;

}//end main
