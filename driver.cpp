#include<iostream>
#include<conio.h>
#include "PolynomialCalculator.h"


int main()
{
	PolynomialCalculator obj(1, 1, 4, 2);
	PolynomialCalculator obj2(1, 1, 3, 1, 6, 5);
	//obj2.display();
	PolynomialCalculator obj3(obj2);
	
	void menu();	// function prototype
	while (true)	// menu function
	{
		menu();
		char c = _getch();
		switch (c)
		{
		case '1':
		{
			obj2 + obj;
			break;
		}
		case '2':
		{
			obj2 - obj;
			break;
		}
		case '3':
		{
			obj2 *= obj;
			break;
		}
		case '4':
		{
			int x = 0;
			std::cout << "enter the value you want to compute" << std::endl;
			std::cin >> x;
			std::cout << "value =  at x("   << x << ") = " << obj.value(x) << std::endl;

			
			break;
		}
		case '5':
		{
			std::cin >> obj;


			break;
		}
		case '6':
		{
			std::cin >> obj;

			break;
		}
		case '7':
		{
			std::cout << obj << std::endl;

			break;
		}
		case '8':
		{
			std::cout << obj2 << std::endl;
			break;
		}
		case 'q':
		{
			std::cout << obj2 << std::endl;
			return 0;
		}
		default:
		{
			std::cout << "Invalid user input" << std::endl;
			break;
		}

		

		} // switch

		_getch();
		system("cls");
	}

	//std::cout << obj << std::endl;
	//std::cout << obj2 << std::endl;
	//std::cout << std::endl << std::endl;
	////obj2 = obj;

	//std::cout << "///" << std::endl;
	////std::cout << obj.value(5) << std::endl;
	////std::cout << obj2 << std::endl;
	//std::cin >> obj;
	//std::cout << obj << std::endl;
	//obj + obj2;
	//std::cout << obj << std::endl;
	//obj.tester();

	
	std::cin.get();
	return 0;
}


std::ostream& operator << (std::ostream& out, PolynomialCalculator& p)
{
	if (*(p.coefficient) == -1 && *(p.exponent) == -1)
	{
		out << "Error, there is no polynomial present here" << std::endl;
	}
	else
	{
		for (int i = p.exponent_size - 1; i >= 0; i--)
		{
			if (p.exponent[i] != 0 && p.coefficient[i] != 0)
			{
				if (p.coefficient[i] > 0 && i != p.exponent_size - 1)
				{
					out << " + ";
				}
				if (p.coefficient[i] < 0)
				{
					out << " ";
				}
				if (p.coefficient[i] == 0)
				{
					out << " + ";
				}
				out << p.coefficient[i] << "x^" << p.exponent[i] << " ";
			}
			
		}
	}



	return out;
}


void menu()	 // function body
{
	std::cout << "Press 1 to add 2 polynomials" << std::endl;
	std::cout << "Press 2 to subtract 2 polynomials" << std::endl;
	std::cout << "Press 3 to multiply 2 polynomials" << std::endl;
	std::cout << "Press 4 to compute the polynomial" << std::endl;
	std::cout << "Press 5 to take an input for polynomial" << std::endl;
	std::cout << "Press 6 to take an input for polynomial" << std::endl;
	std::cout << "Press 7 to display polynomial 1" << std::endl;
	std::cout << "Press 8 to display the polynomial 2" << std::endl;
	std::cout << "Press q to quit" << std::endl;



}
