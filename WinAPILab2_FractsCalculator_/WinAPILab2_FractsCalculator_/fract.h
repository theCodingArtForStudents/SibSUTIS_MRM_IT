#ifndef FRACT_H
#define FRACT_H

#include <iostream>
#include "labhelper.h"

class Fract
{
protected:
	int numerator;
	int denominator;
private:
	void reduce();

public:
	Fract();
	Fract( int numerator, int denominator );

	void setNumerator( int numerator );
	void setDenominator( int denominator );

	static Fract Sum( const Fract& a, const Fract& b );
	static Fract Sub( const Fract& a, const Fract& b );
	static Fract Mul( const Fract& a, const Fract& b );
	static Fract Div( const Fract& a, const Fract& b );

	static int LCM( const int& det1, const int& det2 ); // NOK -- eng. is "least common multiple" LCM
	static int GCD( const int& a, const int& b );		// NOD -- eng. is "greatest common divisor" GCD

	int getNumerator();
	int getDenominator();

	std::string toString();
};

#endif // FRACT_H
