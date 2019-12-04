#ifndef BigInt_h
#include <string>
#include <vector>

using namespace std;

class BigInt {
private:

	vector<char> v;
	vector<int>::iterator it;
	vector<int>::reverse_iterator rit;
	

public:
	BigInt();

	BigInt(int num);

	BigInt(string num);

	friend ostream& operator << (ostream& out, BigInt num);

	BigInt operator+(BigInt num);

	bool operator==(int num);

	BigInt operator-(int num);

	BigInt operator++(int num);

	bool operator<(const BigInt& num) const;

	bool operator <=(int num);

	void print();


};




#endif
