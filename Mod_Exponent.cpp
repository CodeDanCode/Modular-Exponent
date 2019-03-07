//Created by Daniel Leach


#include <iostream>
#include <string>
#include <vector>
using namespace std;

void binary(int, vector<int> &);
int modularExpo(int, vector<int> &, int, int);

int main() {

	vector<int> K;
	int k;
	int a, n; 
	

	cout << "please enter the base: " << endl;
	cin >> a;
	cout << "please enter exponent: " << endl;
	cin >> k;
	cout << "please enter modulous: " << endl;
	cin >> n;
	binary(k, K);


	//used to find binary number being stored in K
	// in the order the numbers will be read by computer.
	cout << "the binary representation stored in vector K is: ";
	for (int i = 0; i < K.size(); i++) {
		cout << K[i] << " ";
	}

	cout << endl;
	cout << endl;

	// used to show the correct binary number to the user.
	// not the computer. has no effect on the outcome of the 
	// program.
	cout << "the binary representation for the exponent is: ";
	for (vector<int>::reverse_iterator i = K.rbegin(); i != K.rend(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	cout << endl;

	//shows the result of modular exponetiation a,k,and n.
	cout <<"the result is " <<  modularExpo(a, K, n, k) << endl;
	cout << endl;

	// used to system pause to beable to see final results.
	// window closes otherwise.
	system("PAUSE");
	return 0;
}

void binary(int k,vector<int> &K) {
	int temp = k;
	int i = 0;
	while (temp > 0) {
		K.push_back(temp % 2);
		temp = (temp - K[i]) / 2;
		i++;
	}

}

int modularExpo(int a, vector<int> &K, int n,int k) {
	
	int b = 1;
	
	if (n == 1) {
		return 0;
	}
	
	if (k == 0) {
		return b;
	}
	int A = a;
	if (K[0] == 1){
		b = a;
	}
	for (int i = 1; i < K.size();i++) {
		A = (A * A) % n;
		if (K[i] == 1) {
			b = (A * b) % n;
		}
	}
	
	return b;
}

