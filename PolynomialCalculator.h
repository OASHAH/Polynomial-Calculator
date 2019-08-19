#pragma once
#include<iostream>
class PolynomialCalculator
{
private:
	int count = 0;
	int* coefficient;
	int* exponent;	// dynamic array of terms, terms are stored in the decreasing order of the exponent.
	int coefficent_size = -1;
	int exponent_size = -1;
public:
	PolynomialCalculator();
	PolynomialCalculator(int e, int c);	// for adding polynomials. e = exponent, c = coefficient.
	PolynomialCalculator(int e1, int c1, int e2, int c2);	// for adding 2 polynomials.
	PolynomialCalculator(int e1, int c1, int e2, int c2, int e3, int c3);	// for adding 3 polynomials.
	PolynomialCalculator(PolynomialCalculator& p);	// copy constructor.

	PolynomialCalculator operator + (PolynomialCalculator p);	// operator for addition.
	PolynomialCalculator operator - (PolynomialCalculator p);	// operator for subtraction.
	void operator += (PolynomialCalculator p);	// subtracts, then stores the resultant value
	void operator -= (PolynomialCalculator p);	// subtracts, then stores the resultant value
	void operator *= (PolynomialCalculator p);	// multiplies, then stores the resultant value
	//PolynomialCalculator& operator = (PolynomialCalculator& p);	// Assign the value of right hand side polynomial to the left hand side polynomial. (allow cascaded assignment operation)
	//PolynomialCalculator operator * (PolynomialCalculator p);	// multiplies and then returns a value.

	void operator = (PolynomialCalculator& p);	// Assign the value of right hand side polynomial to the left hand side polynomial.

	int value(int v);	// computes, then returns the values of the operator.
	int power(int x, int p);	// computes the exponent values.

	void tester();	// only for use for checking the values of the exponent and coefficient.


	void display();	// display all polynomials.
	~PolynomialCalculator();
	friend std::ostream& operator << (std::ostream& out, PolynomialCalculator& p);	// overloaded function, displays the output polynomial.
	friend std::istream& operator>>(std::istream&in, PolynomialCalculator& p);
};

