#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){
	double balance, inter_rate, pay;
	cout << "Enter initial loan: ";
	cin >> balance;
	cout << "Enter interest rate per year (%): ";
	cin >> inter_rate;
	cout << "Enter amount you can pay per year: ";
	cin >> pay;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";

	for(int year = 1; balance > 0; year++){
		//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
		//you can change input argument of 'setprecision()' to see the effect
		cout << fixed << setprecision(2); 
		cout << setw(13) << left << year;
		cout << setw(13) << left << balance;
		cout << setw(13) << left << inter_rate * balance / 100;
		balance += inter_rate * balance / 100;
		cout << setw(13) << left << balance;
		if(balance < pay){
			cout << setw(13) << left << balance;
			balance = 0;
		}else{
			cout << setw(13) << left << pay;
			balance -= pay;
		}
		cout << setw(13) << left << balance;
		cout << "\n";
	}
	
	return 0;
}
