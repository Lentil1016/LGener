#include "marker.h"
#include<iostream>
using namespace std;

marker::marker()
{
}


marker::~marker()
{ 
}

marker* marker::next()
{
	return p_next;
}

marker* marker::next(marker*p)
{
	p_next = p;
	return p;
}

void marker::mark(int x, int y)
{
	rank = x;
	pos = y;
}

marker* marker::print()
{
	cout << "\n{"  <<rank+1<< "," <<(int) pos+1 << "} ";
	return p_next;
}

unsigned char marker::consult(int * p)
{
	*p = rank;
	return pos;
}