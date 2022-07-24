#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;
int main()
{
    ifstream fin("input.txt");
    if (!fin.is_open()) { cerr << "Can't open input file!" << endl;  exit(1); }

    while (!fin.eof())
    {
       string st;
       getline(fin, st);
       float temp;
       stringstream line(st);

       while (!line.eof()) 
       {
           line >> temp;
           cout << temp << "\t";
       }
       cout << endl;
    }

    return 0;
}


// #include <fstream>
// #include <iostream>
// #include <string>
// #include <sstream>

// using namespace std;

// int main(int argc, char* argv[])
// {
//     std::cout << "Program path: " << argv[0] << std::endl;
//     if(argc != 2){
//         std::cout << "First param should be a file name" << std::endl;
//         return 1;
//     }
//     std::string fileName{argv[1]};

//     ifstream fin(fileName);
//     if (!fin.is_open()) { cerr << "Can't open " << fileName << " file!" << endl;  exit(1); }

//     while (!fin.eof())
//     {
//         string st;
//         getline(fin, st);
//         float temp;
//         stringstream line(st);

//         while (line >> temp)
//         {
//             cout << temp << "\t";
//         }
//         cout << endl;
//     }

//     return 0;
// }