#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//reference to later defined function "hoursTime"
double hoursTime (int departure, int arrival);

int main()
{
  //set up input and output files. .txt files
  ifstream fin ("flight.txt");
  ofstream fout ("flightResults.txt");

  //declare variables
  string strDestination = "";
  string strFlightNum = "";
  int connections = 0, departure = 0, arrival = 0, travelTime = 0, layover = 0;

  //output error message if there is a problem opening "flight.txt"
  if (!fin)
  {
    cout << "file not opened properly";
    system ("PAUSE");
    return EXIT_FAILURE;
  }

  //format output file with proper headers
  fout << "Flight #  "<<"Destination  " << "# Connections  " << "Departure  " << "Arrival  " <<"Travel Time"<<endl;

  //while there are flights numbers (and therefore flights) to be iterated...
  while (fin>>strFlightNum)
  {
    fin >> strDestination >> connections;

    if(connections==1)
      fin >> departure >> arrival >> layover;
    
    else
    {
      fin >> departure >> arrival;

      fout<<setw(8)<<strFlightNum<<setw(10)<<strDestination<<setw(12);
      fout<<connections<<setw(15)<<departure<<setw(10)<<arrival<<setw(10)<<hoursTime(departure,arrival)<<endl;
    }
  }
}

double hoursTime (int departure,int arrival)
{
  return (arrival-departure);
}
