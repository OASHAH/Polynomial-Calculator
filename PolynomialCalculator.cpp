#include "PolynomialCalculator.h"


#include<string>
PolynomialCalculator::PolynomialCalculator()
{
	
	std::cout << "Default constructor has been called" << std::endl;

}

PolynomialCalculator::PolynomialCalculator(int e, int c) // for adding polynomials. e = exponent, c = coefficient.
{
	
		exponent = new int[e];
		coefficient = new int[c];
		for (int i = 0; i < e - 1; i++)
		{
			exponent[i] = 0; // others are defined as zero.
		}
		exponent[e - 1] = e; // this the the largest and last value of the exponent.


		for (int i = 0; i < c - 1; i++)
		{
			coefficient[i] = 0;
		}
		coefficient[c - 1] = c;

	exponent_size = e; // count of exp and coefficient.
	coefficent_size = c;
}
PolynomialCalculator::PolynomialCalculator(int e1, int c1, int e2, int c2) // for adding 2 polynomials. 
//(e represesnts the exponents, and c = coefficient)
{
	int temp_highest;	// stores the value of the bigger exponent.
	if (e1 > e2)
	{
		temp_highest = e1;
	}
	else if (e1 == e2)
	{
		temp_highest = e1;	// doesn't matter which
	}
	else
	{
		temp_highest = e2;
	}


	exponent = new int[temp_highest - 1];
	coefficient = new int[temp_highest - 1];
	exponent_size = temp_highest;
	coefficent_size = temp_highest;


	// declaring exponent  and coefficient values.
	for (int i = 0; i < temp_highest - 1; i++)
	{
		if (i == e1 - 1)
		{
			exponent[i] = e1;
			coefficient[i] = c1;
			continue;
		}
		if (i == e2 - 1)
		{
			exponent[i] = e2;
			coefficient[i] = c2;
			continue;
		}
		exponent[i] = 0;
		coefficient[i] = 0;
	}
	exponent[temp_highest - 1] = temp_highest;


	if (temp_highest == e1)
	{
		coefficient[temp_highest - 1] = c1;

	}

	else if (temp_highest == e2)
	{
		coefficient[temp_highest - 1] = c2;
		
	}

}

	
PolynomialCalculator::PolynomialCalculator(int e1, int c1, int e2, int c2, int e3, int c3)	// for adding 3 polynomials.
{
	
	int temp2; // for use in bsort
	int temp[3] = { e1, e2, e3 };
	// using bubble sort method.
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (temp[j] > temp[j + 1])
			{
				temp2 = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = temp2;
			}
		}
	} // the values sorted in ascending order.

	/*for (int i = 0; i < 3; i++)
	{
		std::cout << temp[i] << std::endl;
	}
*/

	std::cout << std::endl;

	exponent = new int[temp[2] - 1];
	coefficient = new int[temp[2] - 1];
	exponent_size = temp[2];
	coefficent_size = temp[2];



	///////////////////////////////////////////////////////
	
	// declaring exponent  and coefficient values.


	for (int i = 0; i < temp[2] - 1; i++)
	{
		if (i == e1 - 1)
		{
			exponent[i] = e1;
			coefficient[i] = c1;
			continue;
		}
		if (i == e2 - 1)
		{
			exponent[i] = e2;
			coefficient[i] = c2;
			continue;
		}
		if (i == e3 - 1)
		{
			exponent[i] = e3;
			coefficient[i] = c3;
			continue;
		}
		exponent[i] = 0;
		coefficient[i] = 0;
	}
	exponent[temp[2] - 1] = temp[2];


	if (temp[2] == e1)
	{
		coefficient[temp[2] - 1] = c1;

	}

	else if (temp[2] == e2)
	{
		coefficient[temp[2]- 1] = c2;

	}

	else if (temp[2] == e3)
	{
		coefficient[temp[2] - 1] = c3;
	}


}


PolynomialCalculator::PolynomialCalculator(PolynomialCalculator& p)	// copy constructor.
{
	//delete exponent
	//delete coefficient
	exponent = new int[p.exponent_size - 1];
	coefficient = new int[p.coefficent_size - 1];

	for (int i = 0; i < p.exponent_size; i++)
	{
		exponent[i] = p.exponent[i];
		coefficient[i] = p.coefficient[i];
	}

	coefficent_size = p.coefficent_size;
	exponent_size = p.exponent_size;
}

void PolynomialCalculator::display()
{
	if (*coefficient == 0 && *exponent == 0)
	{
		std::cout << "Error, there is no polynomial present here" << std::endl;
	}
	else
	{
		for (int i = exponent_size - 1; i >= 0; i--)
		{
			if (coefficient[i] > 0 && i != exponent_size - 1)
			{
				std::cout << " + ";
			}
			if (coefficient[i] < 0)
			{
				std::cout << " ";
			}
			if (coefficient[i] == 0)
			{
				std::cout << " + ";
			}
			std::cout << coefficient[i] << "x^" << exponent[i] << " ";
		}
	}
}



PolynomialCalculator PolynomialCalculator::operator + (PolynomialCalculator p)	// operator for addition.
{
	
	for (int i = 0; i < p.exponent_size; i++)
	{
		coefficient[i] += p.coefficient[i];
		if (exponent[i] == 0)
		{
			exponent[i] = p.exponent[i];

		}

		
	}

	
	PolynomialCalculator temp;
	delete temp.exponent;
	delete temp.coefficient;
	temp.exponent = new int[exponent_size - 1];
	temp.coefficient = new int[coefficent_size - 1];
	
	for (int i = 0; i < exponent_size; i++)
	{
		temp.exponent[i] = exponent[i];
		temp.coefficient[i] = coefficient[i];

	}

	temp.coefficent_size = coefficent_size;
	temp.exponent_size = exponent_size;

	return temp;

	
	
}

PolynomialCalculator PolynomialCalculator::operator - (PolynomialCalculator p)	// operator for subtraction.
{
	for (int i = 0; i < p.exponent_size; i++)
	{
		coefficient[i] -= p.coefficient[i];
		if (exponent[i] == 0)
		{
			exponent[i] = p.exponent[i];

		}


	}


	PolynomialCalculator temp;
	delete temp.exponent;
	delete temp.coefficient;
	temp.exponent = new int[exponent_size - 1];
	temp.coefficient = new int[coefficent_size - 1];

	for (int i = 0; i < exponent_size; i++)
	{
		temp.exponent[i] = exponent[i];
		temp.coefficient[i] = coefficient[i];

	}

	temp.coefficent_size = coefficent_size;
	temp.exponent_size = exponent_size;

	return temp;
}


void PolynomialCalculator::operator += (PolynomialCalculator p)	// stores the resultant value
{
	for (int i = 0; i < p.exponent_size; i++)
	{
		coefficient[i] += p.coefficient[i];
		if (exponent[i] == 0)
		{
			exponent[i] = p.exponent[i];

		}


	}
}


void PolynomialCalculator::operator -= (PolynomialCalculator p)	// stores the resultant value
{
	for (int i = 0; i < p.exponent_size; i++)
	{
		coefficient[i] -= p.coefficient[i];
		if (exponent[i] == 0)
		{
			exponent[i] = p.exponent[i];

		}


	}
}

void PolynomialCalculator::operator *= (PolynomialCalculator p)	// multiplies, then stores the resultant value
{

	int count = exponent[exponent_size - 1] + p.exponent[p.exponent_size - 1];
	//std::cout << "count = " << count << std::endl;
	
	int* temp_coefficient = new int[count];
	int* temp_exponent = new int[count];

	for (int i = 0; i <= count; i++)
	{
		temp_coefficient[i] = 0;
		temp_exponent[i] = 0;
		//coefficient[i] = 0;
	}
	
	for (int i = 0; i < p.exponent_size; i++)
	{
		for (int j = 0; j < exponent_size; j++)
		{
			temp_coefficient[i + j] = temp_coefficient[i + j] + (p.coefficient[i] * coefficient[j]);
			temp_exponent[i + j] = (p.exponent[i] + exponent[j]);
		}
	}


	
	exponent_size += p.exponent_size;
	coefficent_size += p.coefficent_size;

	


	exponent = new int[exponent_size];
	coefficient = new int[coefficent_size];

	for (int i = 0; i < count; i++)
	{
		exponent[i] = temp_exponent[i];
		coefficient[i] = temp_coefficient[i];
	}

	
	



	// now assigning the c array to the other array.


	
}
//PolynomialCalculator PolynomialCalculator::operator * (PolynomialCalculator p)	// multiplies and then returns a value.
//{
//
//	int count = exponent[exponent_size - 1] + p.exponent[p.exponent_size - 1];
//	//std::cout << "count = " << count << std::endl;
//
//	int* temp_coefficient = new int[count];
//	int* temp_exponent = new int[count];
//
//	for (int i = 0; i <= count; i++)
//	{
//		temp_coefficient[i] = 0;
//		temp_exponent[i] = 0;
//		//coefficient[i] = 0;
//	}
//
//	for (int i = 0; i < p.exponent_size; i++)
//	{
//		for (int j = 0; j < exponent_size; j++)
//		{
//			temp_coefficient[i + j] = temp_coefficient[i + j] + (p.coefficient[i] * coefficient[j]);
//			temp_exponent[i + j] = (p.exponent[i] + exponent[j]);
//		}
//	}
//
//	
//
//	
//
//
//
//
//	// now assigning the c array to the other array.
//
//
//}

//polynomialcalculator& polynomialcalculator::operator = (polynomialcalculator& p)	// assign the value of right hand side polynomial to the left hand side polynomial. (allow cascaded assignment operation)
//{
//
//	
//	polynomialcalculator temp;
//	delete temp.exponent;
//	delete temp.coefficient;
//	temp.exponent = new int[p.exponent_size - 1];
//	temp.coefficient = new int[p.coefficent_size - 1];
//
//	for (int i = 0; i < p.exponent_size; i++)
//	{
//		temp.exponent[i] = p.exponent[i];
//		temp.coefficient[i] = p.coefficient[i];
//
//	}
//
//	temp.coefficent_size = p.coefficent_size;
//	temp.exponent_size = p.exponent_size;
//
//	//temp.display();
//	return temp;
//}


void PolynomialCalculator::operator = (PolynomialCalculator& p)
{
		//PolynomialCalculator temp;
		//temp.exponent = new int[p.exponent_size - 1];
		//temp.coefficient = new int[p.coefficent_size - 1];
	
		/*delete exponent;
		delete coefficient;*/
		//exponent = coefficient = NULL;
		exponent = new int[p.exponent_size - 1];
		coefficient = new int[p.coefficent_size - 1];

		for (int i = 0; i < p.exponent_size; i++)
		{
			exponent[i] = p.exponent[i];
			coefficient[i] = p.coefficient[i];
		}
	
		coefficent_size = p.coefficent_size;
		exponent_size = p.exponent_size;
	
		//temp.display();
		
}

void PolynomialCalculator::tester()	// for checking the values of the coefficient and exponent.
{
	std::cout << "Listing the exponent values:" << std::endl;
	for (int i = 0; i < exponent_size; i++)
	{
		std::cout << i + 1 << " = " << exponent[i] << std::endl;
	}

	std::cout << "Listing the coefficient values:" << std::endl;
	for (int j = 0; j < coefficent_size; j++)
	{
		std::cout << j + 1 << " " << coefficient[j] << std::endl;
	}
}

int PolynomialCalculator::power(int x, int p)
{
	int temp = x;
	for (int i = 0; i < p - 1; i++)
	{
		x = x * temp;
	}

	return x;
}

int PolynomialCalculator::value(int v)	// computes, then returns the values of the operator.
{
	int sum = 0;
	for (int i = 0; i < exponent_size; i++)
	{
		sum += (      coefficient[i] * power(v, exponent[i])    );
	}
	return sum;

}

PolynomialCalculator::~PolynomialCalculator()
{
	//delete[] exponent;
	//delete[] coefficient;
	std::cout << "Polynomial has been deleted" << std::endl;
}

std::istream& operator>>(std::istream&in,PolynomialCalculator& p)
{
	
	std::string input;
	std::cout << "Enter the string" << std::endl;
	std::getline(in, input);

	int string_size = input.size();
	int tokens = 0;
	for (int i = 0; i < string_size; i++)
	{
		if (input[i] == '+' || input[i] == '-')
		{
			tokens++;
		}

	}
	tokens += 1; // the number of individual polynomials.

	input.append( "+");	// this will add the positive sign in between individual polynomials.
	if (isdigit(input[0]))
	{
		input.insert(0, "+");
	}
	if (input[0] == 'x')
	{
		input.insert(0, "+");
	}
	string_size = input.size();	// new string lenght


	//std::cout << input << std::endl;

	// now seperating the polynomials into individual tokens.
	std::string token_array[20];
	int token_num = 0;
	int j = 0;
	
	for (int i = 1; i < string_size; ++i) // so the first positive sign is skipped and it then runs in a loop finding the other '+'s.
		if (input[i] == '+' || input[i] == '-')
		{
			token_array[token_num] = input.substr(j, i - j);
			token_num++;
			j = i;
		}

	//std::cout << token_array[0] << std::endl;
	//std::cout << token_array[1] << std::endl;

	int count = 0;
	
	for (int i = 0; i < token_num; ++i)
	{
		int tokenSize = token_array[i].size();
		for (int j = 0; j < tokenSize; ++j)
		{
			if (token_array[i][j] == '^')
			{
				//expon[i] = stoi(monomStr[i].substr(j + 1, monomSize - j));
				//coeff[i] = stod(monomStr[i].substr(0, j));
				count++;

				break;
			}
		}

	}

	int* exp = new int[count];	// new declaration of the exponent array.
	int* coeff = new int[count];	// new declaration of the coefficient array.
	int* bsort_exp = new int[count];	// bsorted exponential.
	int* coeff_temp = new int[count];
	int* temp = new int[count]; // just assigned index values.
	

	////////////////////////////////////////////////////////////////////

	for (int i = 0; i < token_num; ++i)
	{
		int tokenSize = token_array[i].size();
		for (int j = 0; j < tokenSize; ++j)
		{
			if (token_array[i][j] == '^')
			{
				exp[i] = stoi(token_array[i].substr(j + 1, tokenSize - j));
				coeff[i] = stoi(token_array[i].substr(0, j));
				break;
			}
		}

	}

	///////////////////////////////////////////////////////////////

	int highest = 0;
	for (int i = 0; i < count; i++)
	{
		if (exp[i] > highest)
		{
			highest = exp[i];
		}
		//std::cout << "Exponent[" << i << "] = " << exp[i] << std::endl;
	}

	//std::cout << "highest =" <<  highest << std::endl;

	
	//////////////////////////////////////

	for (int i = 0; i < count; i++)
	{
		bsort_exp[i] = exp[i];
	}


	int temp2; // for use in bsort
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (bsort_exp[j] > bsort_exp[j + 1])
			{
				temp2 = bsort_exp[j];
				bsort_exp[j] = bsort_exp[j+1];
				bsort_exp[j + 1] = temp2;


			}
			
		}
	}
	/////////////////////////////////////////////////
/*
	for (int i = 0; i < count; i++)
	{
		std::cout << bsort_exp[i] << std::endl;
	}
*/
	/////////////////////////////////////////////////

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (bsort_exp[i] == exp[j])
			{
				temp[i] = j;
			}
		}
	}
	//////////////////////////////////////////////////

	for (int i = 0; i < count; i++)
	{
		coeff_temp[i] = coeff[temp[i]];
	}


	/*std::cout << "coeff temp = " << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << coeff_temp[i] << std::endl;
	}*/



	//////////////////////////////////////////////

	/*std::cout << "coeff = " << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << " t" << i << " " << coeff[i] << std::endl;
	}*/

	//////////////////////////////////////////////////////////


	/*std::cout << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << "Coefficient[" << i << "] = " << coeff[i] << std::endl;
	}*/



	//-------------------------------------------------------------------
	// int highest = the highest exponent.
	// coeff_temp[count]
	// bsort_exp[count]

	//delete[] p.exponent;
	//delete[] p.coefficient;
	p.exponent = new int[highest - 1];
	p.coefficient = new int[highest - 1];
	p.exponent_size = highest;
	p.coefficent_size = highest;


	/*for (int i = 0; i < highest - 1; i++)
	{

		
		if (i == bsort_exp[i] - 1)
		{
			p.exponent[i] = bsort_exp[i];
			p.coefficient[i] = coeff_temp[i];
			continue;
		}
		if (i == coeff_temp[i] - 1)
		{
			p.exponent[i] = bsort_exp[i];
			p.coefficient[i] = coeff_temp[i];
			continue;
		}
		
		
		p.exponent[i] = 0;
		p.coefficient[i] = 0;
	}*/


	for (int i = 0; i < highest - 1; i++)
	{
		p.exponent[i] = 0;
		p.coefficient[i] = 0;

	}

	for (int i = 0; i < highest - 1; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (i == bsort_exp[j] - 1)
			{
				p.exponent[i] = bsort_exp[j];
				p.coefficient[i] = coeff_temp[j];
			}
		}
	}





	




	
	p.exponent[highest - 1] = highest;
	p.coefficient[highest - 1] = coeff_temp[count - 1];


	

	std::cout << "Value entered" << std::endl;



	return in;



}
