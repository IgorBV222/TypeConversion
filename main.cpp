#include <iostream>
#include "Car.h"
#include "Van.h"

int main() {
	setlocale(LC_ALL, "Russian");

	std::cout << "Задача 1. Преобразуйте double i = 32200030001.1 в int по правилам языка C++, выведите экран на результат. Предположите, что произошло?" << '\n';
	double i = 32200030001.1;
	//std::cout << "double i = " << i << '\n';

	std::cout << "Преобразавание double i = 32200030001.1 в int по правилам языка C++:\n";
	int i_int = static_cast<double>(i);
	std::cout << "int i = " << i_int << '\n';//int i = -2147483648 полученное значение больше чем вмешает тип int
	//от –32768 до 32767 (при 2 байтах) или от −2 147 483 648 до 2 147 483 647 (при 4 байтах)
	//Присвоение идет по кругу и в результате получили число -2147483648

	std::cout << "Полученное значение больше чем вмешает тип int\n(от –32768 до 32767 (при 2 байтах) или от −2 147 483 648 до 2 147 483 647 (при 4 байтах))\nПрисвоение идет по кругу и в результате получили число -2147483648\n";
	std::cout << "------------------------\n";

	std::cout << "Задача 2. Приведите пример снятия константности с указателя на double." << '\n';
	const double* p_i = &i;
	double* pp_i = const_cast<double*>(p_i);
	std::cout << "------------------------\n";

	std::cout << "Задача 3.Создайте класс Car и Van, второй наследуется от первого. В main проведите успешный upcast, успешный downcast\nи два неуспешных downcast’a: с указателем и ссылкой.\nЗакомментированным кодом предложите версию downcast’a которая будет считаться неопределенным поведением." << '\n';

	Car car;
	Van van;
	Car* pCar = &van;//успешный upcast
	pCar->NameClass();
	Van* pVan = static_cast<Van*>(pCar);//успешный downcast
	pVan->NameClass();
	Van* pVan2 = (Van*)&car;//неуспешный downcast (неопределенное поведение)
	pVan2->NameClass();//успешный downcast
	Van* pVan3 = (Van*)pCar;//неуспешный downcast
	pVan3->NameClass();//успешный downcast

	return 0;
}