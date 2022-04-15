#include <iostream>
#include <bitset>
using namespace std;

// CHANGE BIT LENGHT OF NUMBERS 
const int bits_length = 32;

/*Auxiliar bitset (remainder of last div)*/
bitset <bits_length> remainder;

/* Auxiliars Functions: sum, rest*/
bitset <bits_length> sum(bitset<bits_length> A, bitset<bits_length> B, bool carry = false){
	bitset<bits_length> r;
	
	for (int i = 0; i < bits_length; i++){
		r[i] = A[i] ^ B[i] ^ carry;
		carry = (A[i] & B[i]) | (B[i] & carry) | (A[i] && carry);
	}	
	
	return r;
}

bitset <bits_length> rest(bitset<bits_length> A, bitset<bits_length> B){
	return sum(A, ~B, true);
}

bitset <bits_length> division(bitset<bits_length> Q, bitset<bits_length> M){
	
	bitset <bits_length> A {0};
	int count = bits_length;
	
	do{
		
		A <<= 1;
		A[0] = Q[bits_length-1];
		Q <<= 1;
		
		A = rest(A, M);
		
		if (A[bits_length-1] == 1){
			Q[0] = 0;
			A = sum(A, M);
		}
		else Q[0] = 1;
		
	}while(--count != 0);
	
	remainder = A;
	return Q;
}


int main(){
	
	int var;
	unsigned long long dividend, divisor;
	
	do{
		cout << "\n\t ** Int Division **\n\n";
	
		cout << "Insert Dividend (unsigned long long): "; cin >> dividend;
		cout << "Insert Divisor  (unsigned long long): "; cin >> divisor;
		
		bitset <bits_length> bits_dividend {dividend};
		bitset <bits_length> bits_divisor {divisor};
		
		cout << "\nDividend bits: "<< bits_dividend << "\n";
		cout << "Divisor  bits: " << bits_divisor << "\n\n";
		
		bitset <bits_length> div_result = division(bits_dividend, bits_divisor);
		
		cout << "RESULTS: ";
		cout << "\n\nDivision Result (Decimal): " << div_result.to_ullong();
		cout << "\nDivision Result  (Binary): " << div_result;
		
		cout << "\n\nRemainder (Decimal): " << remainder.to_ullong();
		cout << "\nRemainder  (Binary): " << remainder;
		
		cout << "\n\nContinue? (1 = Yes / 0 = No)\n\nInsert option:  "; cin >> var;
		
	}while(var == 1);
	
	return 0;
}