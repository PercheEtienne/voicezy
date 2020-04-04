#include"../librairie/parseMeteo.c"

char* rep = "{\"coord\":{\"lon\":72.85,\"lat\":19.01},\"weather\":[{\"id\":721,\"main\":\"Haze\",\"description\":\"haze\",\"icon\":\"50n\"}],\"base\":\"stations\",\"main\":{\"temp\":299.15,\"feels_like\":301.61,\"temp_min\":299.15,\"temp_max\":299.15,\"pressure\":1013,\"humidity\":78},\"visibility\":3500,\"wind\":{\"speed\":3.1,\"deg\":340},\"clouds\":{\"all\":0},\"dt\":1584818420,\"sys\":{\"type\":1,\"id\":9052,\"country\":\"IN\",\"sunrise\":1584839452,\"sunset\":1584883195},\"timezone\":19800,\"id\":1275339,\"name\":\"Mumbai\",\"cod\":200}";

int main(){

	char *Meteo = infoMeteo(rep);
	char *Temperature = infoTempEnKelvin(rep);

	printf("Meteo = %s\n",Meteo);
	printf("Temperature = %s\n",Temperature);
	return 0;
}
