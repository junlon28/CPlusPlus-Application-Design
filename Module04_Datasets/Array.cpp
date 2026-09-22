#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{ 
    ifstream file("iris_small.csv");

    if (!file.is_open())
    {
        cout << "Could not open file." << endl;
        return 1;
    }


    double sepalLength[5];
    double sepalWidth[5];
    double petalLength[5];

    string header;
    getline(file, header);

    cout << "Header: " << header << endl;

    char comma;

    for (int f = 0; f <5; f++)
    {
    file >>  sepalLength[f] >> comma
        >> sepalWidth[f] >> comma
        >> petalLength[f];
    }
    file.close();

    cout << "Sepal Length\tSepal Width\tPetal Length" << endl;

    for (int i = 0; i < 5; i++)
    {

    cout << sepalLength[i] << "\t\t\t\t"
        << sepalWidth[i] << "\t\t\t"
        << petalLength[i] << endl;
    }
    
    double* ptr = sepalLength;
    cout << "Pointer Value: " << *ptr << endl;

    return 0;
}