/*
Use of map associative container
*/
#include<iostream>
using namespace std;
#include<string>
#include<map>//include this header file to access/call the built in methods
int main()
{   
    //creating a map called mapType, which we take a string and an integer value as a key value pair
    typedef map<string,int> mapType;
    mapType population;

    //The first two lines of code have created an empty map
    population.insert(pair<string,int>("Maharashtra", 542785290));
    population.insert(pair<string,int>("Gujarat", 785290));
    population.insert(pair<string,int>("Karnataka", 542785290));
    population.insert(pair<string,int>("Himachal Pradesh", 54278529));
    population.insert(pair<string,int>("Kerala", 542785290));
    population.insert(pair<string,int>("Tamil Nadu", 542785290));
    population.insert(pair<string,int>("Uttar Pradesh", 542785290));
//as this is an "Associative" container and not a "sequential" container, the values will be stored randomly
//mapType (name).insert(pair<key values>(the values to be inserted));

//creating an iterator
mapType::iterator iter;

//using inbuilt functions to display the size of the map
cout<<"Size of the map: "<<population.size()<<endl;

//taking user input
string state_name;
cout<<"Enter the state name :"<<endl;
cin>>state_name;

//assigning the iterator to finding the state name
iter=population.find(state_name);
if(iter!=population.end())//if it found the name before reaching the end of the map
{
    cout<<state_name<<" population is: "<<iter->second;
    //iter->second will give the population
    //iter->first will give the state name
}
else{
    cout<<"The state isnt present in our map ! :(";//the value was not found in the map or the spelling might be wrong
}

population.clear();

/*
********OUTPUT**************

Size of the map: 7
Enter the state name :
Maharashtra
Maharashtra population is: 542785290

*/

}
