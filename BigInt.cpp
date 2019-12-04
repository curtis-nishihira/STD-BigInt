// Isaiah Guardado
// CECS 282-05
// Prog 5 - STL Library BigInt

#include "BigInt.h"
#include <iostream>
#include <iostream>
#include <string>

using namespace std;

BigInt::BigInt() {
	v.push_back(0);
}


BigInt::BigInt(int num) {
	while (num > 9) {
		int digit = num % 10;
		v.push_back(digit);
		num /= 10;
	}
	if (num < 10) {
		v.push_back(num);
	}
}

BigInt::BigInt(string num) {

	for (int i = num.size() - 1; i >= 0; i--) {
		v.push_back(num[i] - '0');
	}
}


ostream& operator << (ostream& out, BigInt num) {
	if (num.v.size() > 10) {
		out << (int)num.v[num.v.size() - 1] << ".";
		int tester = 0;
		for (int i = num.v.size() - 2; i > 0; i--) {
			if (tester > 9) {
				out << "e" << num.v.size();
				return out;
			}
			tester++;
			out << (int)num.v[i] << "";
		}
	}
	else if (num.v.size() <= 10) {
		for (int i = num.v.size() - 1; i > -1; i--) {
			out << (int)num.v[i] << "";
		}
	}
	return out;
}

BigInt BigInt::operator+(BigInt test) {
	BigInt temp(*this);
	int carry = 0;

	while (test.v.size() != temp.v.size()) {
		if (test.v.size() < temp.v.size()) {
			test.v.push_back(0);
		}
		if (temp.v.size() < test.v.size()) {
			temp.v.push_back(0);
		}
	}

	for (int i = 0; i < temp.v.size(); i++) {
		if (carry == 1) {
			temp.v[i] += 1;
			carry = 0;
		}
		
		if ((temp.v[i] + test.v[i]) > 9) {
			carry = 1;
		}
		temp.v[i] = test.v[i] + temp.v[i] - carry * 10;
	}

	if (carry == 1) {
		temp.v.push_back(1);
	}

	return temp;
}

void BigInt::print() {

	for (int i = v.size() - 1; i > -1; i--) {
		cout << (int)v[i];
	}
}

bool BigInt::operator==(int one) {
	if (v.size() == 1) {
		if (v[0] == (char)one) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}



BigInt BigInt::operator++(int num) {
	BigInt temp(*this);
	*this = *this + BigInt(1);
	return temp;
}




bool BigInt::operator<=(const int num) {
	BigInt temp (num);
	if (v.size() < temp.v.size()) {
		return true;
	}
	else if (temp.v.size() < v.size()) {
		return false;
	}
	
	if (v.size() == temp.v.size()) {
		for (int i = v.size() - 1; i > -1; i--) {
			if (v[i] < temp.v[i]) {
				return true;
			}
			else if (temp.v[i] < v[i]) {
				return false;
			}
		}
		return true;
	}
}


bool BigInt::operator<(const BigInt& num) const {
	if (v.size() < num.v.size()) {
		return true;
	}
	else if (v.size() == num.v.size()) {
		for (int i = v.size() - 1; i > -1; i--) {
			if (num.v[i] < v[i]) {
				return false;
			}
			else if (v[i] < num.v[i]) {
				return true;
			}
		}
		return false;
	}

	else {
		return false;
	}
}

BigInt BigInt::operator-(int num) {
	BigInt temp(*this);

	if (temp.v[0] < num) {
		temp.v[0] = (temp.v[0] + 10) - num;
		for (int i = 1; i < temp.v.size(); i++) {
			if (temp.v[i] > 0) {
				temp.v[i] = temp.v[i] - 1;
				break;
			}
			else {
				temp.v[i] = 9;
			}
		}
	}
	else {
		temp.v[0] -= num;
	}
	
	
	if (temp.v[temp.v.size() - 1] == 0 && temp.v.size() > 1) {
		temp.v.erase(temp.v.begin() + temp.v.size() - 1);
	}
	return temp;
}
