#include "../librairie/lightsensor.c"

int main (void) 
{
	while(1)
	{
		int lux;
		lux=getLuminositeEnLux();
		printf("il fait : %d Lux \n", lux);
	}
	return 0;
}
