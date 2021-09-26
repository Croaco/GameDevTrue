#include <iostream>
#include <sstream>


template <class TYPE> class vec3 
{
	TYPE x, y, z;

	vec3 operator+ (vec3 vector1)
	{
		return vec3 (vector1.x + this->x , vector1.y + this->y, vector1.z + this->z);
	}

	vec3 operator- (vec3& vector1)
	{
		return vec3 (this->x - vector1.x, this->y - vector1.y, this->z - vector1.z);
	}

	vec3 operator+= (vec3& vector1)
	{		
		return vec3 (vector1.x + this->x, vector1.y + this->y, vector1.z + this->z);
	}

	vec3 operator-= (vec3& vector1)
	{		
		return vec3 (this->x - vector1.x, this->y - vector1.y, this->z - vector1.z);
	}

	vec3 operator= (vec3& vector1)
	{
		return vec3 (vector1.x, vector1.y, vector1.z);
	}

	bool operator== (vec3& vector1)
	{
		return vector1.x == this->x  && vector1.y == this->y && vector1.z == this->z;
	}

	vec3::vec3()
	{

	}

	vec3::vec3(TYPE p1, TYPE p2, TYPE p3)
	{
		this->x = p1;
		this->y = p2;
		this->z = p3;
	}
	 
	void Zero()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	bool isZero(vec3 vector1)
	{
		return vector1.x == 0 && vector1.y == 0 && vector1.z == 0;
	}

	int distanceTo(vec3 vector1)
	{

	}

	vec3::~vec3() //Destructor
	{

	}
};

int main()
{
	vec3 <int> vector();
}