#pragma once
using namespace std;
#include<iostream>
#include<string.h>
#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
	int mone;
	int mehane;
public:

	double Return_Fraction() const//return value of frac
	{
		return ((double)mone / (double)mehane);
	}
	friend istream& operator>>(istream & is, Fraction& f)//input
	{
		char divSign;
		is >> f.mone >> divSign >> f.mehane;
		if (f.mehane == 0)
			f.mehane = 1;

		return is;
	}
	friend ostream& operator<<(ostream& os, const Fraction& f) //output
	{
		return os << f.mone << "/" << f.mehane << endl;
	}
	bool operator==(const Fraction& f)const
	{
		return ((this->mone == f.mone) && (this->mehane == f.mehane));
	}
	bool operator>(const Fraction& f)const {
		return (this->Return_Fraction() > f.Return_Fraction());
	}
	
};



#endif