#include <iostream>

void PruebaArgumentos(int argc, char** argv)
{
	//si el programa fue lanzado con argumentos..
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			std::cout << argv[i] << "\n";
			//toda acadena de texto termina con un /0
			int j = 0;
			int value = 0;
			std::cout << " ";

			// argv[0][0]  


			do
			{
				value = (int)argv[i][j];
				std::cout << argv[i][j] << " = " << value << " 0x" << std::hex << value << "\n ";
				j++;
			} while (argv[i][j] != 0);


			std::cout << "\n";

		}
	}
	else
	{
		std::cout << "No se dieron argumentos. Cerrando\n";
	}
}

void Promedio(int argc, char** argv)
{
	//ejercicio 2 de apuntadores
//forma C de asignar memoria 
//int* x = (int*) malloc(sizeof(int));
// forma C++ de asignar memoria
	int* x = new int;

	*x = 99;
	std::cout << "sizeof int " << sizeof(int) << "\n";
	std::cout << " x :" << *x << " en " << x << "\n";

	*x = 'k';
	std::cout << "sizeof int " << sizeof(int) << "\n";
	std::cout << " x :" << *x << " en " << x << "\n";

	*(x + 1) = 18;
	std::cout << " x+1 :" << *(x + 1) << " en " << x + 1 << "\n";

	int* y = new int[100];
	char seguir;
	bool Continuale = true;
	memset(y, 0, sizeof(int));

	int* contador = new int;
	*contador = 0;
	float yeet;
	yeet = 0;


	for (int i = 0; i < 100; i++)
	{
		if (Continuale)
		{
			yeet += 1;
			std::cout << "dame los valores tonto " << "\n";
			std::cin >> y[i];
			std::cout << " y[ " << i << " ] = " << y[i] << "\n";
			*contador += y[i];
		}
		if (Continuale || Continuale == false)
		{
			std::cout << "Quieres seguir? Presiona Y para seguir N para cerrar el programa: " << "\n";
			std::cin >> seguir;
		}
		if (seguir == 'Y' || seguir == 'y')
		{
			Continuale = true;
			continue;
		}
		else  if (seguir == 'N' || seguir == 'n')
		{
			break;
		}
		else
		{
			std::cout << "Letra erronea" << "\n";
			i -= 1;
			Continuale = false;
		}
	}
	float promedio = *contador / yeet;
	std::cout << " Promedio = " << promedio << "\n";
}


int main(int argc, char** argv)
{
	//apuntador a funcion
	void (*proceso)(int, char**) = nullptr;

	//preguntar al usuario la funcion deseada
	std::cout << "Funciones disponibles: \n";
	std::cout << "  1. Prueba de argumentos \n";
	std::cout << "  2. Promedio: \n";
	std::cout << "Ingresa el numero de la funcion que quieres \n";

	int seleccion;
	std::cin >> seleccion;
	std::cout << seleccion << "mem: " << &seleccion << "\n";
	if (seleccion == 1)
		proceso = &PruebaArgumentos;
	else if (seleccion == 2)
		proceso = &Promedio;
	else
	{
		std::cout << "Opcion no valida\n";
		main(argc, argv);
	}

	(*proceso)(argc, argv);
	return 0;
}