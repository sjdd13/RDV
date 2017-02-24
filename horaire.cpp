#include <iostream>
#include "horaire.h"

Horaire::Horaire(): d_h{0}, d_min{0}
{}

Horaire::Horaire(int h, int min): d_h{h}, d_min{min}
{}

int Horaire::getH() const
{
	return d_h;
}

int Horaire::getMin() const
{
	return d_min;
}

void Horaire::setH(int h)
{
	d_h = h;
}

void Horaire::setMin(int min)
{
	d_min = min;
}

void Horaire::addHeures(int v)
{
	d_h += v;
	d_h = d_h % 24;
}

void Horaire::addMinutes(int v)
{
	d_min += v;
	this->addHeures(d_min/60);
	d_min = d_min % 60;
}

std::ostream& operator<<(std::ostream& os, const Horaire& h)
{
	os << h.getH() << ":" << h.getMin() << std::endl;
	return os;
}

bool Horaire::operator<(const Horaire& h) const
{
	if(d_h < h.getH())
	{
		return true;	
	}
	else if(d_h > h.getH())
	{
		return false;
	}
	else
	{
		if(d_min < h.getMin())
		{
			return true;
		}
		else if(d_min > h.getMin())
		{
			return false;
		}
	}
}

bool Horaire::operator>(const Horaire& h) const
{
	if(d_h > h.getH())
	{
		return true;	
	}
	else if(d_h < h.getH())
	{
		return false;
	}
	else
	{
		if(d_min > h.getMin())
		{
			return true;
		}
		else if(d_min < h.getMin())
		{
			return false;
		}
	}
}

bool Horaire::operator==(const Horaire& h) const
{
	if(d_h == h.getH() && d_min == h.getMin())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Horaire::operator!=(const Horaire& h) const
{
		if(d_h != h.getH() || d_min != h.getMin())
	{
		return true;
	}
	else
	{
		return false;
	}
}

