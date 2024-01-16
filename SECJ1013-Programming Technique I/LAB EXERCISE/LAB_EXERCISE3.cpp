/* THIS PROGRAM IS TO HELP THE MINISTRY OF HEALTH (MOH) TO DETERMINE THE 
STATUS OF A ZONE BY CALCULATIONF THE NUMBER OF ACTIVE CASES FOR COVID 19. */
#include <iostream>
#include <limits>

using namespace std;

// TASK 6 Function prototypes
void dispStatus(int);
void getInput(int&, int&, int&, int&);
void dispOutput(int);
int calcAverage(int, int);

// TASK 5 Main function
int main() {
    string stateName;
    string highState;
    int totalCase, newCase, totalDeath, totalRecover;
    int totalActiveC = 0;
    int numState = 0;
    int highCase = -1;
    
    while (numState < 5) {
        cout << "<<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>>>>" << endl;
        cout << "State name : ";
        getline(cin, stateName);

        getInput(totalCase, newCase, totalDeath, totalRecover);

        int activeCase = totalCase + newCase - totalDeath - totalRecover;

        dispOutput(activeCase);

        totalActiveC = totalActiveC + activeCase;
        numState++;

        if (activeCase > highCase) {
            highCase = activeCase;
            highState = stateName;
        }

        cout << "Press <ENTER> to continue..." ;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "<<<<<<<<<<<<<<< ACTIVE CASE >>>>>>>>>>>>>" << endl;
    cout << "Total : " << totalActiveC << endl;
    cout << "Highest : " << highCase << " (" << highState << ")" << endl;
    cout << "Average for " << numState << " states : " << calcAverage(numState, totalActiveC) << endl;

    return 0;
}

// Function definitions
// TASK 1
void dispStatus(int activeCase) {
    if (activeCase > 40)
        cout << "Status : Red Zone\n" << endl;
    else if (activeCase >= 21 && activeCase <= 40)
        cout << "Status : Orange Zone\n" << endl;
    else if (activeCase >= 1 && activeCase <= 20)
        cout << "Status : Yellow Zone\n" << endl;
    else
        cout << "Status : Green Zone\n" << endl;
}

// TASK 2
void getInput(int& totalCase, int& newCase, int& totalDeath, int& totalRecover) {
    cout << "Total cases : ";
    cin >> totalCase;
    cout << "New cases : ";
    cin >> newCase;
    cout << "Total death : ";
    cin >> totalDeath;
    cout << "Total recovered : ";
    cin >> totalRecover;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

// TASK 3
void dispOutput(int activeCase) {
    cout << "\n<<<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>>>>>" << endl;
    cout << "Active cases : " << activeCase << endl;
    dispStatus(activeCase);
}

// TASK 4
int calcAverage(int numState, int totalActiveC)
{
    int average = totalActiveC / numState;
}

