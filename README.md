# Polynomial-Calculator
It computes a polynomial equation that a user can input.

This project has the following features:

Plus +: Add two polynomials and return the resultant polynomial

Plus-equal +=: Add the second polynomial in the first and store the resultant n the first polynomial

Minus -: Subtract the two polynomials and return the resultant polynomial

Minus-equal -=: Subtract the second polynomial from the first and store the resultant n the first polynomial

Multiply *: Multiply two polynomials and return the resultant

Multiply-equal *=: Multiply the second polynomial with the first and store the resultant n the first polynomial

Assignment =: Assign the value of right hand side polynomial to the left hand side polynomial. (allow cascaded
assignment operation)

Value (): Overload this operator which takes an integer a and compute the value of the polynomial where the
variable x is replaced by the value of a. For example consider the polynomial P: 2x^2+9x-3, the value of P when
x = 2 is P(2) = 23

Stream insertion <<: Output the polynomial on the screen and it should also allow the cascaded outputs of
multiple polynomials.

Stream extraction >>: Input the polynomial from the user. The user will input the polynomial in the following
format
