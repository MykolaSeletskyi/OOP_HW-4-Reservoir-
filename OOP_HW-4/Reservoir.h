#pragma once
#include <string.h>
class Reservoir
{
public:
	enum class typeReservoirs { LAKE, SEA, RIVER, PUDDLE };
private:
	static size_t number_of_reservoirs;
	char* name = nullptr;
	typeReservoirs typeReservoir = typeReservoirs::PUDDLE;
	size_t width = 0;
	size_t length = 0;
	size_t maximumDepth = 0;
public:
	Reservoir(const char* name = "NONAME")
	{
		setNameReservoir(name);
		number_of_reservoirs++;
	};
	Reservoir(typeReservoirs typeReservoir, const char* name = "NONAME"):typeReservoir(typeReservoir)
	{
		number_of_reservoirs++;
		setNameReservoir(name);
	};
	Reservoir(size_t width, size_t length, size_t maximumDepth, typeReservoirs typeReservoir, const char* name = "NONAME"):
	width(width),
	length(length),
	maximumDepth(maximumDepth),
	typeReservoir(typeReservoir)
	{
		
		number_of_reservoirs++;
		setNameReservoir(name);
	};

	void setNameReservoir(const char* name);
	void setTypeReservoir(typeReservoirs typeReservoir)
	{
		this->typeReservoir = typeReservoir;
	}
	void setWidth(size_t width) {
		this->width = width;
	}
	void setLength(size_t length) {
		this->length = length;
	}
	void setMaximumDepth(size_t maximumDepth) {
		this->maximumDepth = maximumDepth;
	}

	char* getNameReservoir()const {
		return name;
	}
	typeReservoirs getTypeReservoir()const
	{
		return typeReservoir;
	}
	size_t getWidth()const {
		return width;
	}
	size_t getLength()const {
		return length;
	}
	size_t getMaximumDepth()const {
		return maximumDepth;
	}

	size_t approximateVolume()const //обєм
	{
		return (width * length * maximumDepth);
	}
	size_t waterSurfaceArea()const//площа
	{
		return (width * length);
	}

	static size_t getNumber_of_reservoirs();
	static bool belonging_to_one_type(Reservoir left, Reservoir right);
	static int areaComparison(Reservoir left, Reservoir right);
	static Reservoir largestReservoir(Reservoir* arr, size_t sizeArr, typeReservoirs typeReservoir);
	~Reservoir()
	{
		delete[]name;
		name = nullptr;
	}
};

