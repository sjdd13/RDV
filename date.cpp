#include <iostream>
#include "date.h"

Dates::Dates(): d_j{0}, d_m{0}, d_a{0}
{}

Dates::Dates(int j, int m, int a): d_j{j}, d_m{m}, d_a{a}
{}

int Dates::getJ() const 
{
	return d_j;
}

int Dates::getM() const
{
	return d_m;
}

int Dates::getA() const
{
	return d_a;
}

void Dates::setJ(int j)
{
	d_j = j;
}

void Dates::setM(int m)
{
	d_m = m;
}

void Dates::setA(int a)
{
	d_a = a;
}

std::ostream& operator<<(std::ostream& os, const Dates& d)
{
	os << d.getJ() << "/" << d.getM() << "/" << d.getA() << std::endl;
	return os;
}

bool Dates::operator<(const Dates& date) const
{
	if(d_a < date.getA())
	{
		return true;	
	}
	else if(d_a > date.getA())
	{
		return false;
	}
	else
	{
		if(d_m < date.getM())
		{
			return true;
		}
		else if(d_m > date.getM())
		{
			return false;
		}
		else 
		{
			if(d_j < date.getJ())
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
	}
}

bool Dates::operator>(const Dates& date) const
{
	if(d_a > date.getA())
	{
		return true;	
	}
	else if(d_a < date.getA())
	{
		return false;
	}
	else
	{
		if(d_m > date.getM())
		{
			return true;
		}
		else if(d_m < date.getM())
		{
			return false;
		}
		else 
		{
			if(d_j > date.getJ())
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
	}
}

bool Dates::operator==(const Dates& date) const 
{
	if(d_a == date.getA() && d_m == date.getM() && d_j == date.getJ())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Dates::operator!=(const Dates& date) const 
{
	if(d_a != date.getA() || d_m != date.getM() || d_j != date.getJ())
	{
		return true;
	}
	else
	{
		return false;
	}
}
