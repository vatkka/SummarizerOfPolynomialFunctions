
#include <iostream>
#include <string>
#include <cassert>

const int MAX = 10;


bool sign(char); 

using namespace std;

int main() {
	bool flag = false,flag1 = false;
	bool check = true;
	int size = INT_MAX;
	char c, c1;
	double coefficient = 0;
	int power = 0;
	bool nextPower = false, addOrSub = true;
	cout << "Enter	polynomial function	in the form :\n P(x) = AnXn + An-1Xn-1+ . . . + A1X + A	";
	cout << "\n\nP1(x) = ";
	double* P1;
	P1 = new double[1];
	while(c = cin.get(), c != '\n') {
		if (c == '+' || c == '-') {

			if (flag == true && flag1 == false && coefficient == 0) {
				power = 1;
				if (power > size - 1) {						//checking whether the array was set correctly
					cerr << "\nThe input was made in the wrong form, try again";
					return 0;
				}
				if (check) {                                //initializing a dynamic array
					size = power + 1;
					P1 = new double[size];
					for (int i = 0; i < size; i++) {
						P1[i] = 0;
					}
					check = false;
				}
				if (P1[power] == 0) {
					if (addOrSub)
						P1[power] = 1;
					else
						P1[power] = -1;
					coefficient = 0;
					nextPower = false;
				}
				else {
					if (addOrSub)
						P1[power] += 1;
					else
						P1[power] += -1;
					coefficient = 0;
					nextPower = false;
				}
			}
			else {
				nextPower = false;
			}
			addOrSub = sign(c);
			flag1 = false;
		}
		else {
			if (c == 'x' || c == 'X') {
				nextPower = true;
				flag = true;
			}
			else
				if (c >= '0' && c <= '9') {
					cin.unget();
					if (nextPower) {
						flag = false;
						flag1 = true;
						cin >> power;
						if (power > size - 1) {						//checking whether the array was set correctly
							cerr << "The input was made in the wrong form, try again";
							return 0;
						}
						if (check) {                                //initializing a dynamic array
							size = power + 1;
							P1 = new double[size];
							for (int i = 0; i < size; i++) {
								P1[i] = 0;
							}
							check = false;
						}
						if (P1[power] == 0) {
							if (coefficient != NULL) {
								P1[power] += coefficient;
							}
							else {
								if (addOrSub)
									P1[power] = 1;
								else
									P1[power] = -1;
							}
							coefficient = 0;
							nextPower = false;
						}
						else {
							if (coefficient != NULL) {
								P1[power] += coefficient;
							}
							else {
								if (addOrSub)
									P1[power] += 1;
								else
									P1[power] += -1;
							}

							coefficient = 0;
							nextPower = false;
						}

					}
					else {
						if (addOrSub) {			  //checking whether the array was set correctly
							cin >> coefficient;
						}
						else {
							cin >> coefficient;
							coefficient *= -1;
						}
					}
				}
		}
	}
	if (c == '\n' && coefficient != 0) {
		if (nextPower) {
			P1[1] = coefficient;
		}
		else
			P1[0] = coefficient;
	}
	if (flag && coefficient == 0) {
		if (P1[1] == 0) {
			if (addOrSub)
				P1[1] = 1;
			else
				P1[1] = -1;
		}
		else {
			if (addOrSub)
				P1[1] += 1;
			else
				P1[1] += -1;

		}

	}


	//for (int i = size - 1; i >= 0; i--) {           //test
	//	if (P1[i] != 0) {
	//		cout << "coefficient = " << P1[i] << " power = " << i << endl;
	//	}
	//}



	coefficient = 0;
	power = 0;
	flag, flag1 = false;
	int size2 = INT_MAX;
	double* P2;
	P2 = new double[1];
	check = true;
	addOrSub = true;
	nextPower = false;
	cout << "\nP2(x) = ";
	while (c = cin.get(), c != '\n') {
		if (c == '+' || c == '-') {

			if (flag==true && flag1 == false && coefficient== 0) {
				power = 1;
				if (power > size2 - 1) {						//checking whether the array was set correctly
					cerr << "\nThe input was made in the wrong form, try again";
					return 0;
				}
				if (check) {                                //initializing a dynamic array
					size2 = power + 1;
					P2 = new double[size2];
					for (int i = 0; i < size2; i++) {
						P2[i] = 0;
					}
					check = false;
				}
				if (P2[power] == 0) {
						if (addOrSub)
							P2[power] = 1;
						else
							P2[power] = -1;
					coefficient = 0;
					nextPower = false;
				}
				else {
						if (addOrSub)
							P2[power] += 1;
						else
							P2[power] += -1;
					coefficient = 0;
					nextPower = false;
				}
			}
			else {
				nextPower = false;
			}		
			addOrSub = sign(c);
			flag1 = false;
		}
		else {
			if (c == 'x' || c == 'X') {
				nextPower = true;
				flag = true;
			}
			else
				if (c >= '0' && c <= '9') {
					cin.unget();
					if (nextPower) {
						flag = false;
						flag1 = true;
						cin >> power;
						if (power > size2 - 1) {						//checking whether the array was set correctly
							cerr << "The input was made in the wrong form, try again";
							return 0;
						}
						if (check) {                                //initializing a dynamic array
							size2 = power + 1;
							P2 = new double[size2];
							for (int i = 0; i < size2; i++) {
								P2[i] = 0;
							}
							check = false;
						}
						if (P2[power] == 0) {
							if (coefficient != NULL) {
								P2[power] += coefficient;
							}
							else {
									if (addOrSub)
										P2[power] = 1;
									else
										P2[power] = -1;
							}
							coefficient = 0;
							nextPower = false;
						}
						else {
							if (coefficient != NULL) {
								P2[power] += coefficient;
							}
							else {
									if (addOrSub)
										P2[power] += 1;
									else
										P2[power] += -1;
							}

							coefficient = 0;
							nextPower = false;
						}

					}
					else {
						if (addOrSub) {			  //checking whether the array was set correctly
							cin >> coefficient;
						}
						else {
							cin >> coefficient;
							coefficient *= -1;
						}
					}
				}
		}
	}
	if (c == '\n' && coefficient != 0) {
		if (nextPower) {
			P2[1] = coefficient;
		}
		else
			P2[0] = coefficient;
	}
	if (flag && coefficient == 0) {
		if (P2[1] == 0) {
				if (addOrSub)
					P2[1] = 1;
				else
					P2[1] = -1;
		}
		else {
				if (addOrSub)
					P2[1] += 1;
				else
					P2[1] += -1;
			
		}

	}


		//for (int i = size2 - 1; i >= 0; i--) {           //test
		//	if (P2[i] != 0) {
		//		cout << "coefficient = " << P2[i] << " power = " << i << endl;
		//	}
		//}

		double* sum;
		int sizeS;
		int count = 0;
		if (size > size2) {
			sizeS = size;
			sum = new double[sizeS];
			for (int i = 0; i < sizeS; i++) {
				sum[i] = 0;
			}
		}
		else {
			sizeS = size2;
			sum = new double[sizeS];
			for (int i = 0; i < sizeS; i++) {
				sum[i] = 0;
			}
		}
		for (int i = 0; i < size; i++) {
			sum[i] += P1[i];
		}
		for (int i = 0; i < size2; i++) {
			sum[i] += P2[i];
		}
		cout << "\nP1(x)+P2(x) = ";
		for (int i = sizeS - 1; i > 0; i--) {
			if (sum[i] != 0) {
				if (count == 0) {
					count++;
					if (sum[i] == 1 || sum[i] == -1) {
						if (sum[i] == 1) {
							cout << "x";
							if (i != 1) {
								cout << i;
							}
						}
						else {
							cout << "-x";
							if (i != 1) {
								cout << i;
							}
						}
					}
					else {
						cout << sum[i];
						cout << 'x';
						if (i != 1)
							cout << i;
					}
				}
				else {
					if (sum[i] == 1 || sum[i] == -1) {

						if (sum[i] == 1) {
							cout << "+x";
							if (i != 1) {
									cout << i;
							}
						}
						else {
							cout << "-x";
							if (i != 1) {
								cout << i;
							}
						}
					}
					else {
						if (sum[i] > 0) {
							cout << '+' << sum[i];
						}
						else {
							cout << sum[i];
						}
						cout << 'x';
						if (i != 1)
							cout << i;
					}

				}
			}
		}

		if (sum[0] != 0) {
			if (sum[0] > 0) {
				cout << '+' << sum[0];
			}
			else {
				cout << sum[0];
			}
		}


		return 0;

	
}


bool sign(char c) {
	if (c == '+') {
		return true;
	}
	else 
		if (c == '-'){
			return false;
		}
}



