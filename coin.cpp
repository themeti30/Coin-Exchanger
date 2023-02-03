// C++ program to accept an amount
// and count number of notes
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void countCurrency_INR(int amount)
{
    int INR[10] = { 2000, 500, 200, 100,
                     50, 20, 10, 5, 2,1 };
    int noteCounter[10] = { 0 };

    // count notes using Greedy approach
    for (int i = 0; i < 10; i++) {
        if (amount >= INR[i]) {
            noteCounter[i] = amount / INR[i];
            amount = amount - noteCounter[i] * INR[i];
        }
    }

    // Print notes
    cout << "Currency Count in INR" << endl;
    for (int i = 0; i < 10; i++) {
        if (noteCounter[i] != 0) {
            cout<<"Rs " << INR[i] << " x "
                << noteCounter[i] << endl;
        }

    }
}

// function to count and
// print currency notes

void countCurrency_USD(int amount)
{
    int USD[7] = {  100,50, 20, 10, 5, 2,1 };
    int noteCounter2[7] = { 0 };

    // count notes using Greedy approach
    for (int i = 0; i < 7; i++) {
        if (amount >= USD[i]) {
            noteCounter2[i] = amount / USD[i];
            amount = amount - noteCounter2[i] * USD[i];
        }
    }

    // Print notes
    cout << "Currency Count in USD" << endl;
    for (int i = 0; i < 7; i++) {
        if (noteCounter2[i] != 0) {
            cout <<"$ "<< USD[i] << " : "
                << noteCounter2[i] << endl;
        }

    }
}
void countCurrency_JPY(int amount)
{
    int JPY[10] = { 10000,5000,2000,1000, 500, 100,
                     50,10, 5,1 };
    int noteCounter3[10] = { 0 };

    // count notes using Greedy approach
    for (int i = 0; i < 10; i++) {
        if (amount >= JPY[i]) {
            noteCounter3[i] = amount / JPY[i];
            amount = amount - noteCounter3[i] * JPY[i];
        }
    }

    // Print notes
    cout << "Currency Count in JPY:" << endl;
    for (int i = 0; i < 10; i++) {
        if (noteCounter3[i] != 0) {
            cout <<"Yen "<< JPY[i] << " : "
                << noteCounter3[i] << endl;
        }

    }
}

void countCurrency_FRANC(int amount)
{
    int FRANC[9] = {  500, 200, 100,
                     50, 20, 10, 5, 2,1 };
    int noteCounter[9] = { 0 };

    // count notes using Greedy approach
    for (int i = 0; i < 9; i++) {
        if (amount >= FRANC[i]) {
            noteCounter[i] = amount / FRANC[i];
            amount = amount - noteCounter[i] * FRANC[i];
        }
    }

    // Print notes
    cout << "Currency Count in FRANC" << endl;
    for (int i = 0; i < 9; i++) {
        if (noteCounter[i] != 0) {
            cout<<"F" << FRANC[i] << " x "
                << noteCounter[i] << endl;
        }

    }
}
int minCoins1(int INR[], int m, int amount)
{
	// table[i] will be storing the minimum number of coins
	// required for i value. So table[n] will have result
	int table[amount+1];

	// Base case (If given value n is 0)
	table[0] = 0;

	// Initialize all table values as Infinite
	for (int i=1; i<=amount; i++)
		table[i] = INT_MAX;

	// Compute minimum coins required for all
	// values from 1 to n
	for (int i=1; i<=amount; i++)
	{
		// Go through all coins smaller than i
		for (int j=0; j<m; j++)
		if (INR[j] <= i)
		{
			int sub_res = table[i-INR[j]];
			if (sub_res != INT_MAX && sub_res + 1 < table[i])
				table[i] = sub_res + 1;
		}
	}

	if(table[amount]==INT_MAX)
		return -1;

	return table[amount];
}

int minCoins2(int USD[], int m, int amount)
{
	// table[i] will be storing the minimum number of coins
	// required for i value. So table[n] will have result
	int table[amount+1];

	// Base case (If given value n is 0)
	table[0] = 0;

	// Initialize all table values as Infinite
	for (int i=1; i<=amount; i++)
		table[i] = INT_MAX;

	// Compute minimum coins required for all
	// values from 1 to n
	for (int i=1; i<=amount; i++)
	{
		// Go through all coins smaller than i
		for (int j=0; j<m; j++)
		if (USD[j] <= i)
		{
			int sub_res = table[i-USD[j]];
			if (sub_res != INT_MAX && sub_res + 1 < table[i])
				table[i] = sub_res + 1;
		}
	}

	if(table[amount]==INT_MAX)
		return -1;

	return table[amount];
}

int minCoins3(int JPY[], int m3, int amount)
{
	// table[i] will be storing the minimum number of coins
	// required for i value. So table[n] will have result
	int table[amount+1];

	// Base case (If given value n is 0)
	table[0] = 0;

	// Initialize all table values as Infinite
	for (int i=1; i<=amount; i++)
		table[i] = INT_MAX;

	// Compute minimum coins required for all
	// values from 1 to n
	for (int i=1; i<=amount; i++)
	{
		// Go through all coins smaller than i
		for (int j=0; j<m3; j++)
		if (JPY[j] <= i)
		{
			int sub_res = table[i-JPY[j]];
			if (sub_res != INT_MAX && sub_res + 1 < table[i])
				table[i] = sub_res + 1;
		}
	}

	if(table[amount]==INT_MAX)
		return -1;

	return table[amount];
}

int minCoins4(int FRANC[],int m4,int amount)
{
	int table[amount+1];
	table[0]=0;
	for(int i=1;i<=amount;i++)
	table[i]=INT_MAX;
	for(int i=1;i<=amount;i++)
	{
		for(int j=0;j<m4;j++)
		if(FRANC[j]<=i)
		{
			int sub_res=table[i-FRANC[j]];
			if(sub_res!=INT_MAX && sub_res+1<table[i])
			table[i]=sub_res+1;
		}
	}
		if(table[amount]==INT_MAX)
		return -1;
		return table[amount];
}

// Driver function
int main()
{
    system(" Color 06 ");

    int choice;
    int amount;
    int INR[10] = { 2000, 500, 200, 100,50, 20, 10, 5, 2,1 };
    int USD[7] = {  100,50, 20, 10, 5, 2,1 };
    int JPY[10] = { 10000,5000,2000,1000, 500, 100,50,10, 5,1 };
    int FRANC[9]={500,200,100,50,20,10,5,2,1};
    int m1=sizeof(INR)/sizeof(INR[0]);
    int m2=sizeof(USD)/sizeof(USD[0]);
    int m3=sizeof(JPY)/sizeof(JPY[0]);
    int m4=sizeof(FRANC)/sizeof(FRANC[0]);
    cout<<"\n"<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t\t*COIN EXCHANGER*"<<endl;
    cout<<"\n---------------------------------------------------------------------------------"<<endl;
    cout<<"DENOMINATIONS OF INDIAN CURRENCY ARE:"<<endl;
    cout<<"1, 2, 5, 10, 20, 50, 100, 200, 500, 2000\n"<<endl;
    cout<<"DENOMINATIONS OF US CURRENCY ARE:"<<endl;
    cout<<"1, 2, 5, 10, 20, 50, 100\n"<<endl;
    cout<<"DENOMINATIONS OF JAPANESE CURRENCY ARE:"<<endl;
    cout<<"1, 5, 10, 50, 100, 500, 1000, 2000, 5000, 10000\n"<<endl;
    cout<<"DENOMINATIONS OF FRANCE CURRENCY ARE:"<<endl;
    cout<<"0.5,1,2, 5, 10, 20, 50, 100, 200,500\n"<<endl;
    
    cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
cout<<"ENTER THE AMOUNT :"<<endl;
    cin>>amount;
    for(;;)
    {
    cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"ENTER THE COUNTRY CURRENCY TO BE EXCHANGED:"<<endl;
    cout<<"1.INDIAN RUPEES"<<endl;
    cout<<"2.US DOLLARS"<<endl;
    cout<<"3.JAPANESE YEN"<<endl;
    cout<<"4.FRANCE FRANC\n"<<endl;
    cin>>choice;
    switch(choice){
    case 1:cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    cout<<"IN INDIAN CURRENCY:"<<endl;
    cout<<"Minimum number of coins required for given amount is\n"<<minCoins1(INR,m1,amount)<<"\n";
    countCurrency_INR(amount);
    break;
    case 2:cout<<"\n---------------------------------------------------------------------------------"<<endl;
    cout<<"IN US CURRENCY:"<<endl;
    cout<<"Minimum number coins required for given amount is\n"<<minCoins2(USD,m2,amount)<<"\n";
    countCurrency_USD(amount);
    break;
    case 3:cout<<"\n---------------------------------------------------------------------------------"<<endl;
    cout<<"IN JAPANEESE CURRENCY:"<<endl;
    cout<<"Minimum number coins required for given amount is\n"<<minCoins3(JPY,m3,amount)<<"\n";
    countCurrency_JPY(amount);
    break;
    case 4:cout<<"\n---------------------------------------------------------------------------------"<<endl;
    cout<<"IN FRANCE CURRENCY:"<<endl;
    cout<<"Minimum number coins required for given amount is\n"<<minCoins4(FRANC, m4,amount)<<"\n";
    countCurrency_FRANC(amount);
    break;
    
    default:exit(0);
    }
    }
   
}
