#include "Reservoir.h"
#include <iostream>
using namespace std;
size_t Reservoir::number_of_reservoirs = 0;
int main() {
	//LAKE, SEA, RIVER, PUDDLE
	Reservoir a(1, 10, 3, Reservoir::typeReservoirs::PUDDLE);
	Reservoir b(1, 10, 3, Reservoir::typeReservoirs::PUDDLE);
	Reservoir c(1, 1, 3, Reservoir::typeReservoirs::PUDDLE);
	Reservoir d(1, 14, 3, Reservoir::typeReservoirs::RIVER);

	//порівняня типів водойм
	cout<<Reservoir::belonging_to_one_type(c, a)<<endl;

	//left>right=1, left==righ=0, left<right=-1
	cout<<Reservoir::areaComparison(a, c)<<endl;//порівняня площ 

	Reservoir x[4] = {a,b,c,d};
	//метод знаходження у масиві водойм найбільшої за площею  водойми вказаного типу
	//повертає обєкт класу Reservoir
	cout << Reservoir::largestReservoir(x, 4, Reservoir::typeReservoirs::PUDDLE).getLength() << endl;

	//кількість водойм (статичне поле)
	cout<< Reservoir::getNumber_of_reservoirs()<< endl;//кількість водойм
	return 0;
}