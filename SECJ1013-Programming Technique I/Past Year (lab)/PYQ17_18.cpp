/* PAST YEAR QUESTION 2017/2018 */

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include <cstdlib>

using namespace std;


// TASK 1
void readScores (string name[], int score[], int& numScores){
	ifstream inFile ("scores.txt");
	
	if (!inFile){
		cout << "ERROR: CANNOT OPEN scores.txt" << endl;
	}
	
	numScores = 0; 	//0.5
	while (inFile >> name[numScores]) //2.5
    {
       	inFile >> score[numScores]; //1
       	numScores++; //1
   	} 	
   	
	
	inFile.close();
}

// TASK 2
int getHighestScore (int score[], int SIZE){
	int indexHigh = 0 ;
	int highest = score[0];
	
	for (int i=1 ; i < SIZE ; i++){
		if (score[i] > highest){
		
			highest = score[i];
			indexHigh = i ;
		}
	}
	
	return indexHigh ;
}

// TASK 3
int getLowestScore (int score[], int SIZE){
	int indexLow = 0;
	int lowest = score[0];
	
	for (int i = 1 ; i < SIZE ; i++){
		if (score[i] < lowest){
		
			lowest = score[i];
			indexLow = i;		
		}	
	}
	
	return indexLow ;
}

// TASK 4
double averageScore (int score[], int SIZE){
	double average = 0;
	double sum = 0;
	
	for(int i=0 ; i < SIZE ; i++){
		sum = sum + score[i];
	}
	average = sum / SIZE ;
		
	return average;
}

// TASK 5
int main(){
	int SIZE;
	string name[100];
	int score[100] = {0};
	
	readScores(name, score, SIZE);
	
	int indexHigh = getHighestScore(score, SIZE);
	
	int indexLow = getLowestScore(score, SIZE);
	
	double average = averageScore(score, SIZE);
	
	
	ofstream outFile ("reportss.txt");
	
	if (!outFile){
		cout << "ERROR : CANNOT OPEN reportss.txt " ;
		return 1;
	}
	
	outFile << setw(15) << left << "PLAYER'S NAME" << "SCORES" << endl;
	outFile << setw(15) << left << "=============" << "======" << endl;
	
	for (int i=0 ; i< SIZE ; i++){
		outFile << setw(16) << left << name[i] << setw(5) << left << score[i] << endl ;
	}

	outFile << "\nHIGHEST SCORE : " << score[indexHigh] << " (" << name[indexHigh] << ") " << endl << endl;

	outFile << "LOWEST SCORE : " << score[indexLow] << " (" << name[indexLow] << ") " << endl << endl;

	outFile << "AVERAGE SCORE : " << setprecision(2) << fixed << average << endl;
	
	outFile.close();
	
	
	return 0;
}
