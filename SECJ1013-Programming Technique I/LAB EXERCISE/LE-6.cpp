/*lAB EXERCISE CHAPTER 6*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Function prototypes
void readFile(const char*, double[], int&);
void computeC(const double[], double[], int);
double average(const double[], int);
char grade(double);
void writeFile(const double[], const double[], int);

int main() {
    double fahrenheit[100];
    double celcius[100];
    int numData = 0;

    readFile("tempF.txt", fahrenheit, numData);
    computeC(fahrenheit, celcius, numData);
    writeFile(fahrenheit, celcius, numData);

    // Printing summary output on the screen
    cout << "Average of the temperature in Celcius: " << fixed << setprecision(1) << average(celcius, numData) << endl;

    int highTemp = 0, medTemp = 0, lowTemp = 0;
    for (int i = 0; i < numData; ++i) 
	{
        char tempGrade = grade(celcius[i]);
        
		if (tempGrade == 'H') 
			highTemp++;
        else if (tempGrade == 'M')	
			medTemp++;
        else if (tempGrade == 'L') 
			lowTemp++;
    }

    cout << "Number of high temperature: " << highTemp << endl;
    cout << "Number of medium temperature: " << medTemp << endl;
    cout << "Number of low temperature: " << lowTemp << endl;

    return 0;
}

// Function definitions
void readFile(const char* fileName, double data[], int& numData) {
    ifstream inputFile(fileName);

    numData = 0;
    while (inputFile >> data[numData]) {
        numData++;
    }
    inputFile.close();
}


void computeC(const double fahrenheit[], double celcius[], int numData) {
    for (int i = 0; i < numData; ++i) {
        celcius[i] = 5.0 / 9.0 * (fahrenheit[i] - 32);
    }
}


double average(const double array[], int numData) {
    if (numData == 0)
		return 0;

    double sum = 0;
    for (int i = 0; i < numData; ++i) {
        sum += array[i];
    }

    return sum / numData;
}

char grade(double temperature) {
	
    if (temperature >= 35.0) 
		return 'H';
    else if (temperature >= 20.0) 
		return 'M';
    else 
		return 'L';
}

void writeFile(const double fahrenheit[], const double celcius[], int numData) {
    ofstream outputFile("summary.txt");

    outputFile << setw(15) << left << "C(Celcius)" << setw(15) << left << "F(Farenheit)" << setw(15) << left << "Description" << endl;
    outputFile << setw(15) << left << "==========" << setw(15) << left << "============" << setw(15) << "===========" << endl;

    for (int i = 0; i < numData; ++i) {
        outputFile << setw(15) << left << fixed << setprecision(2) << celcius[i];
        outputFile << setw(15) << fixed << setprecision(2) << fahrenheit[i];
        outputFile << setw(15) << grade(celcius[i]) << endl;
    }

    outputFile.close();
}

