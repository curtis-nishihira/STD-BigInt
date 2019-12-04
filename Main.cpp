#include <iostream>
#include <time.h>
#include <iomanip>
#include "BigInt.h"
#include <vector>
#include <map>

using namespace std;

static map<BigInt, BigInt> FibMap;


BigInt GoldRabbits(BigInt n);
void pause() { cout << "Press Enter to continue..."; getchar();}

int main() {
	
	BigInt B1("123456789123456789123456789123456789");
	BigInt B2(B1);
	BigInt MAX(INT_MAX);
	cout << "B1:" << B1 << "\nB2:" << B2 << "\nMAX:" << MAX << endl;
	pause();
	B1.print();
	cout << endl;
	pause();

	BigInt b1(1);
	BigInt b2(2);

	cout << (b2 - 1) << endl;
	cout << (b1 - 1) << endl;
	
	for (BigInt i = 0; i <= 3000; i++) {
		cout << "\nGoldRabbits(" << i << ") = " << GoldRabbits(i);
	}
	cout << "\n\n\n\n" << endl;

	pause();


	map<BigInt, BigInt>::iterator it;

	it = FibMap.begin();

	while (it != FibMap.end()) {
		cout << it->first << ":";
		cout << it->second << endl;
		it++;
	}

	cout << "\nThis is the value of GoldRabbits(3000)\n\n";
	BigInt gR3000 = GoldRabbits(BigInt(3001));
	gR3000.print();

	


	


	pause();
}


BigInt GoldRabbits(BigInt n) {
	//static map<BigInt, BigInt> FibMap;

	if (n == 0 || n == 1) {
		FibMap[n] = BigInt(1);
	}

	else if (FibMap.find(n) == FibMap.end()) {
		return FibMap[n] = FibMap[n - 1] + FibMap[n - 2];
	}

	return FibMap[n];
}
