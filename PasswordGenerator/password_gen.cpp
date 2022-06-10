#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
	---------------------------
	Secure Password Generator
	by: Halilovic Mustafa

*/
unsigned int passLength, symbols, numbers, LowercaseCharacters, UppercaseCharacters, stop=0;
string password;

void Heading()
{
	cout << "--------------------------------" << endl;
	cout << "    Secure Password Generator   " << endl;
	cout << "--------------------------------" << endl;
}

void Set()
{
	cout << "Password Length: "; cin >> passLength;
	cout << "Include Symbols(1-yes/0-no): "; cin >> symbols;
	cout << "Include Numbers(1-yes/0-no): "; cin >> numbers;
	cout << "Include Lowercase Characters(1-yes/0-no): "; cin >> LowercaseCharacters;
	cout << "Include Uppercase Characters(1-yes/0-no): "; cin >> UppercaseCharacters;
}

void Reset()
{
	passLength = 0, symbols = 2, numbers = 2, LowercaseCharacters = 2, UppercaseCharacters = 2,stop=0;password="";
}

void Generator()
{
	srand(time(NULL));
	int n1, n2, n3, n4;
	char NumArr[10] = {'0','1','2','3','4','5','6','7','8','9'};
	char SimArr[16] = {'!','@', '#', '$',' %', '^', '&', '*', '(', ')', '_', '-', '+', '=', '<', '>'};
	char LowChArr[26] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
	char UppChArr[26] = {'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};

	while(passLength>0)
	{
		if(numbers==1) {
		n1 = rand()%10; 
		password += NumArr[n1]; passLength--;
		if(passLength==0) goto a;
		}
		if(symbols==1) {
		n2 = rand()%16;
		password += SimArr[n2]; passLength--;
		if(passLength==0) goto a;
		}
		if(LowercaseCharacters==1) {
		n3 = rand()%26;
		password += LowChArr[n3]; passLength--;
		if(passLength==0) goto a;
		}
		if(UppercaseCharacters==1) {
		n4 = rand()%26;
		password += UppChArr[n4]; passLength--;
		if(passLength==0) goto a;
		}
	}
	a:cout << "Password: " << password << endl;
	stop = 1;
}

int main()
{
	poc:Reset();
	while(stop==0)
	{
		Heading();
		Set();
		Generator();
		system("pause");
		system("cls");
	}
	stop = 0; goto poc;
	
	return 0;
}
