#include<iostream>
#include<fstream>
using namespace std;
int main()
{ 
    //this program is for reading files.
    //If a file is not existing, then this program wont create a new file. A file already has to be existing in order for this program to work
    ifstream ifs("My.txt");
    //ifstream ifs;
    //ifs.open("My.txt");
    if(ifs.is_open()) cout<<"File is opened"<<endl;
    string name;
    int roll;
    string branch;
    int age;
    ifs>>name>>roll>>branch>>age;
    ifs.close();
    cout<<"Name"<<name<<endl;
    cout<<"Roll number"<<roll<<endl;
    cout<<"Branch"<<branch<<endl;
    cout<<"Age"<<age<<endl;
    // eof stands for end of file that is a built in function that can be used to check whether we have reached the end of file or not

}