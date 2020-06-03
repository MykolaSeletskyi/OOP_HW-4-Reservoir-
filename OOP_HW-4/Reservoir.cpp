#include "Reservoir.h"

void Reservoir::setNameReservoir(const char* name)
{
	if (name == nullptr || strlen(name) == 0)
		return;
	if (this->name != nullptr)
	{
		delete[] this->name;
	}
	size_t size = strlen(name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, name);
}

size_t Reservoir::getNumber_of_reservoirs()
{
	return number_of_reservoirs;
}
bool Reservoir::belonging_to_one_type(Reservoir left, Reservoir right)
{
	return (left.typeReservoir==right.typeReservoir);
}

int Reservoir::areaComparison(Reservoir left, Reservoir right)
{
	return (left.waterSurfaceArea() > right.waterSurfaceArea()?1: (left.waterSurfaceArea() < right.waterSurfaceArea()?-1:0));
}

Reservoir Reservoir::largestReservoir(Reservoir *arr,size_t sizeArr, typeReservoirs typeReservoir)
{
	size_t largestArea = 0;
	size_t resultIndex = 0;
	bool noResult = true;
	for (size_t i = 0; i < sizeArr; i++)
	{
		if (arr[i].getTypeReservoir() == typeReservoir&& arr[i].approximateVolume()> largestArea)
		{
			largestArea = arr[i].approximateVolume();
			resultIndex = i;
			noResult = false;
		}
	}
	if (!noResult)
	{
		return arr[resultIndex];
	}
	return Reservoir();
}
