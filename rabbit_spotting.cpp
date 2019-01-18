#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int timeInMinutes (int militaryTime)
{
	return ((militaryTime - militaryTime % 100)/100)* 60 + (militaryTime % 100);
}

//hypotenuse of triangle with a,b sides xValue, yValue is distance to rabbit in metres
double distanceInMeters (double xValue, double yValue)
{
	return sqrt(pow(xValue, 2) + pow(yValue, 2));
}

//heading in degrees with East as 0/360, North at 90
double findHeading (double xValue, double yValue)
{
	double heading = 0;
	
	if (xValue == 0)
	{
		if (yValue > 0)
			heading = 90;
		else
			heading = -90;
	}
	else if (yValue == 0)
	{
		if (xValue > 0)
			heading = 0;
		else 
			heading = 180;
	}
	else
	{
	double relativeHeading = fabs(atan(yValue/xValue));
	if (yValue > 0 && xValue > 0)
		heading = relativeHeading / M_PI * 180;
	else if (yValue > 0 && xValue < 0)
		heading = 180 - (relativeHeading / M_PI * 180);
	else if (yValue < 0 && xValue > 0)
		heading = -(relativeHeading / M_PI * 180);
	else
		heading = -180 + (relativeHeading / M_PI * 180);
	}
	return heading;
} //end findHeading

int main ()
{
	int militaryTime = 0, previousTime = 0, timeDifference = 0, shortestTime= 1000000;
	double xValue = 0, yValue = 0;
	
	ifstream fin ("rascally_rabbits.txt");
	ofstream fout ("rabbit_spotting_results.txt");
	
	//output error message if problem occurs during open of file
	if (!fin)
	{
		cout << "Error opening file" << endl;
		system ("PAUSE");
		return EXIT_FAILURE;
	}
	
	//format output file header
	fout << "Time in Minutes" << setw(21) << "Distance in Meters" << setw(11) 
		<< "Heading" << endl;
	
	//while there are spottings to iterate...
	while (fin >> militaryTime >> xValue >> yValue)
	{
		fout << setw(8) << timeInMinutes(militaryTime) << fixed 
			 << setprecision(2) << setw(21) << distanceInMeters(xValue, yValue) 
			 << setw(18) << findHeading(xValue, yValue) << endl;
		
		timeDifference = timeInMinutes(militaryTime) - previousTime;
		
		if (timeDifference < shortestTime)
			shortestTime = timeDifference;
		
		previousTime = timeInMinutes(militaryTime);
	}
	
	fout << "Shortest time between rabbits is " << shortestTime << " minutes.";
	
	fin.close();
	fout.close();
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
/*
INPUT: rascally_rabbits.txt
SAMPLE OUTPUT:
Time in Minutes   Distance in Meters    Heading
      12                82.75            174.73
      32                76.84             -7.40
      48               121.01            174.26
      55               121.06             -5.97
      96               217.00           -179.68
     108                64.01            179.02
     115                36.36            -21.63
     266               306.02           -179.27
     322                10.52            122.18
     327               272.47           -177.45
     415                42.68             10.26
     479                19.72            157.34
     541                37.18            -11.79
     602               291.40              1.49
     742                64.01             -0.98
     890                10.52             57.82
    1004                19.72           -157.34
    1132                42.68           -169.74
    1222                 2.20             90.00
    1271                13.00            180.00
    1424                 2.20              0.00
    1439                 2.20            -90.00
Shortest time between rabbits is 5 minutes.
*/
