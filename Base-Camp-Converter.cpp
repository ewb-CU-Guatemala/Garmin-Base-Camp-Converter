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
    /*
    All elemtes of the struct are declared to be strings as i wont be doing any math simply moving them to a .csv and excel will recognize them
    as numbers. Also I first tried this with all the data as doubles and was haing rounding issues.
    */
    point(){}
    // default constructor
    point( string Id, string trksegId, string Lat, string Lon, string Ele, string Date)
    {
    id = Id;
    trksegid = trksegId;
    lat= Lat;
    lon = Lon;
    ele = Ele;
    date= Date;
    }
    // the constructor i actually use

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
    // clearing the first lines that are all irelevant for my implemetation.
    string one;
    string two;
    string three;
    string four;
    string five;
    string six;
    while(getline(datafile, line))
    {
        stringstream ss(line, '\t');
        ss>>one;
        ss>>two;
        ss>>three;
        ss>>four;
        ss>>five;
        ss>>six;
        point a =point(one, two, three, four, five, six);
        data.push_back(a);
    }
    //cout<< data.size()<< " should equal 807 something"<< endl;
    // was checking to see that it pulled out all data
    datafile.close();
}
void output(vector <point> &data)
{
    ofstream datafile;
    datafile.open("output.csv");
    datafile << "ID, trksegID, lat, lon, ele, date" << endl;
    for(int i=0; i<data.size() ; i++)
    {
        cout<< i<< endl;
        point a= data.at(i);
        datafile<< a.id<< ','<< a.trksegid <<','<< a.lat << ','<<a.lon <<','<< a.ele<<','<< a.date<< endl;
    }
}
int main(int argc, char *argv[])
{
    if(argc !=2)
    {
        cout<< "please enter the filename of the txt file you would like to read from"<< endl;
        return 0;
    }
    vector <point> data;
    reader(argv[1], data);
    output(data);

}