//THIS PROGRAM SHOWS SET 3
#include<iostream>
using namespace std;

int main()
{
	int num, digit;
	int product = 1;
	
	//input statement
	cout << "Enter an integer number: ";
	cin >> num;
	
	//make sure the number is positive value
	if (num<0){
		num = -num;
	}
	
	//calculate the products of digits
	while (num>0){
		digit = num % 10;          //use remainder
		num = num / 10;
		product *= digit;
		cout << digit;             //display digits
	
		if (num>0){
			cout << " * ";
		}
	}
	
	cout << " = " << product << endl;
	
	//determine the sum is multiples of 4, 5, and/or 7
	bool mult4 = (product % 4 == 0);
	bool mult5 = (product % 5 == 0);
	bool mult7 = (product % 7 == 0);
	
	cout << product << " is";
	
	if (mult7){
		cout << " multiples of 7";
	}
		
	if (mult5){
		if (mult7){
			cout << " and";
		}
		cout << " multiples of 5";
	}
	
	if (mult4){
		if (mult7 || mult5){
			cout << " and";
		}
		cout << " multiples of 4" ;
	}
	return 0;
}
