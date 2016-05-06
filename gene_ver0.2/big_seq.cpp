#include "big_seq.h"


big_seq::big_seq()
{
}


big_seq::~big_seq()
{
}

void big_seq::gnrt(unsigned char* p)
{
	int i;
	for (i = 0; i < 25; i++)
	{
		dna[i] = *(p+i);
	}
}
