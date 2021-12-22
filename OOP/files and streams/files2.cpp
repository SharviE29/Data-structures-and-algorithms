// Streams 
// •I/O Streams are used for input and output data to and from the program
// •C++ provides class for accessing input output operations
// •Iostream is a base class for all classes
// •Istream is for input
//  •Cin is the object of istream
//  •ostream is for output
//  •Cout is an object of ostream•
//  •ifstream is a file input stream
//  •ofstream is a file output stream

// Writing in a File 

 int main()
 {
    ofstream of("Test.txt",ios::trunc);
    of<<"John"<<endl; 
    of<<25<<endl;  
    of<<"CS"<<endl; 
    of.close();
}

// Reading from File

int main()
{
    ifstream ifs("Test.txt");
    string name;
    int roll;
    string branch; 
    ifs>>name>>roll>>branch;
    cout<<name<<endl<<roll<<endl<<branch<<endl;    
    ifs.close();
}