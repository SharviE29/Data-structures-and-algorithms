#include<iostream>
#include<fstream>
using namespace std;
int main()
{
  ofstream ofs("My.txt");
  //ofstream is a class that belongs to the set of fstream libraries present in the header file

  //ofs is an object created
  //ios::trunc #Mode 1: If already existing file is present, then its will add the contents in it

  //ios::app Then the existing contents in the file will be saved along with the newly added commands

  ofs<<"Sharvi"<<endl;
  ofs<<21226<<endl;
  ofs<<"Computer Engineering"<<endl;
  ofs<<19<<endl;
  ofs.close();//file should be closed
}