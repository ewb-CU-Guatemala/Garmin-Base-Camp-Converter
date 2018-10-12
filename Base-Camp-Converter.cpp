//Author: Christian F. Sousa
// Written on October 12 2018
#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;
struct point
{
    string id;
    string trksegid;
    string lat;
    string lon;
    string ele;
    string date;

    point(){}
    point( string Id, string trksegId, string Lat, string Lon, string Ele, string Date)
    {
    id = Id;
    trksegid = trksegId;
    lat= Lat;
    lon = Lon;
    ele = Ele;
    date= Date;

    }

};

void reader(string filename, vector <point> &data)
{
    ifstream datafile;
    datafile.open(filename);
    if( datafile.fail())
    {
        cout<< "Error opening file"<< endl;
        return;
    }
    string line;
    string holder;
    for( int i=0; i<43; i++)
    {
        getline(datafile, line);
    }
    getline(datafile, line);
    cout<< line<< endl;
}
/*
void printer()
{

}
i*/
int main(int argc, char *argv[])
{
    if(argc !=2)
    {
        cout<< "please enter the filename of the txt file you would like to read from"<< endl;
    }
    vector <point> data;
    reader(argv[1], data);

}