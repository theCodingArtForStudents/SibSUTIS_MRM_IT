#include "fract.h"
#include <iostream>
void Fract::reduce()
{
  int nod = GCD(numerator, denominator);

  numerator /= nod;
  denominator /= nod;
}

int Fract::GCD(const int& a,const int& b)
{
	int _a = a, _b = b;
  while(_a > 0 && _b > 0){
    if(_a > _b)
      _a %= _b;
    else
      _b %= _a;
  }

  return _a + _b;
}


int Fract::LCM(const int& det1, const int& det2)
{	
		return det1*det2 / GCD(det1, det2);
}

Fract::Fract()
{

}

Fract::Fract(int numerator, int denominator):numerator(numerator), denominator(denominator)
{
	reduce();
}

Fract Fract::Sum(const Fract& a, const Fract& b)
{
	Fract result;
	if (a.denominator == b.denominator) {
		result.setDenominator(a.denominator);
		result.setNumerator(a.numerator + b.numerator);
	}
	else 
	{
		int nok = Fract::LCM(a.denominator, b.denominator);
		int additionaFactorA = nok / a.denominator,
			additionaFactorB = nok / b.denominator;

		result.setDenominator( (a.denominator < b.denominator) 
								?(a.denominator * additionaFactorA) 
								:(b.denominator * additionaFactorB)
							 );
		result.setNumerator( (int)(a.numerator * additionaFactorA + b.numerator * additionaFactorB) );
	}
	
	return result;
}

Fract Fract::Sub(const Fract & a, const Fract & b)
{
	Fract result;
	if (a.denominator == b.denominator) {
		result.setDenominator(a.denominator);
		result.setNumerator(a.numerator + b.numerator);
	}
	else
	{
		int nok = Fract::LCM(a.denominator, b.denominator);
		int additionaFactorA = nok / a.denominator,
			additionaFactorB = nok / b.denominator;

		result.setDenominator((a.denominator < b.denominator)
			? (a.denominator * additionaFactorA)
			: (b.denominator * additionaFactorB)
		);
		result.setNumerator(a.numerator * additionaFactorA - b.numerator * additionaFactorB);
	}

	return result;
}

Fract Fract::Mul(const Fract & a, const Fract & b)
{
	 
	return Fract( a.numerator * b.numerator, a.denominator * b.denominator);
}

Fract Fract::Div(const Fract & a, const Fract & b)
{
	return Fract( a.numerator * b.denominator, a.denominator * b.numerator);
}

void Fract::setNumerator(int numerator)
{
  this->numerator = numerator;
}

void Fract::setDenominator(int denominator)
{
  if(denominator != 0)
    this->denominator = denominator;
  else{
    this->denominator = 1;
    std::cout << "Fract::Error::denominator must be greater then zero." << std::endl;
  }
}



int Fract::getNumerator()
{
  return numerator;
}

int Fract::getDenominator()
{
  return denominator;
}

std::string Fract::toString()
{
	return std::string( LabHelper::IntToString(numerator) + "/" + LabHelper::IntToString(denominator) );
}

