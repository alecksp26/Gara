#include "moto.h"
#include "automobile.h"
#include "gara.h"

int main() 
{
	std::string *array;
	std::string array2[10];
	array = new std::string[10];

	for(int i=0; i<10; i++) {std::cout << array[i] << " ";}

	std::cout << std::endl;

	for(int i=0; i<10; i++) {std::cout << array[i] << " ";}

	std::cout << std::endl;

	Moto m(120, 10000, "Ducati", "1000cc");
	Auto a(160, 8000, "Fiat Punto", "diesel", "1.300 MTJ");
	Auto b(180,90000,"Tesla","elettrico","2000 madonne");


	Gara gara(10, 10);
	gara.agg_partecipante(m); //moto m
	gara.agg_partecipante(a); //auto a
	gara.agg_partecipante(b);
	gara.partenza();
	std::cout << m << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	//gara.stampa_classifica();
}