//THIS PROGRAM SHOWS SET 2
#include<iostream>
using namespace std;

int main()
{
	int num, digit;
	int sum=0;
	
	//input statement
	cout << "Enter an integer number: ";
	cin >> num;
	
	//make sure number is positive value
	if (num<0){
		num = -num;
	}
	
	//calculate the sum of digits 
	while (num>0){
		digit = num % 10;         //use remainder
		num = num / 10;           
		sum += digit;
		cout << digit;            //display digit
		
		if (num>0){
			cout << " + ";
		}
	}
	
	cout << " = " << sum << endl;   
	
	//determine the sum is even or odd number
	if (sum % 2 == 0){
		cout << sum << " is even number";
	}
	else{
		cout << sum << " is odd number";
	}
	
	//determine the sum is multiples of 4 and/or 5
	bool mult4 = (sum % 4 == 0);
	bool mult5 = (sum % 5 == 0);
	
	
	if (mult4){
		cout << " & multiples of 4" ;
	}
	
	if (mult5){
		if (mult4){
			cout << " and";
		}
		cout << " multiples of 5" ;
	}
	
	return 0;
}
