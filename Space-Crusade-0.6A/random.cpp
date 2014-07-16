#include "random.h"
#include <cstdlib>


int iRandom(Range r)
{
	return r.iLow + rand() % ((r.iHigh + 1) - r.iLow);
}

int Random(int low, int high)
{
	return low + rand() % ((high + 1) - low);
}

float fRandom(Range r)
{
	return r.fLow + (float)rand()/((float)RAND_MAX/(r.fHigh-r.fLow));
}

float Random(float low, float high)
{
	return low + (float)rand()/((float)RAND_MAX/(high-low));
}
