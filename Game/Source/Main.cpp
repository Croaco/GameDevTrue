#include "App.h"

#include "Defs.h"
#include "Log.h"

// NOTE: SDL redefines main function
#include "SDL/include/SDL.h"

// NOTE: Library linkage is configured in Linker Options
//#pragma comment(lib, "../Game/Source/External/SDL/libx86/SDL2.lib")
//#pragma comment(lib, "../Game/Source/External/SDL/libx86/SDL2main.lib")

#include <stdlib.h>


template <class TYPE> class vec3
{
	TYPE x, y, z;

	vec3 operator+ (vec3 vector1)
	{
		return vec3(vector1.x + this->x, vector1.y + this->y, vector1.z + this->z);
	}

	vec3 operator- (vec3& vector1)
	{
		return vec3(this->x - vector1.x, this->y - vector1.y, this->z - vector1.z);
	}

	vec3 operator+= (vec3& vector1)
	{
		return vec3(vector1.x + this->x, vector1.y + this->y, vector1.z + this->z);
	}

	vec3 operator-= (vec3& vector1)
	{
		return vec3(this->x - vector1.x, this->y - vector1.y, this->z - vector1.z);
	}

	vec3 operator= (vec3& vector1)
	{
		return vec3(vector1.x, vector1.y, vector1.z);
	}

	bool operator== (vec3& vector1)
	{
		return vector1.x == this->x && vector1.y == this->y && vector1.z == this->z;
	}

	vec3::vec3()
	{

	}

	//vec3::vec3(TYPE p1, TYPE p2, TYPE p3)
	//{
	//	this->x = p1;
	//	this->y = p2;
	//	this->z = p3;
	//}

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

enum MainState
{
	CREATE = 1,
	AWAKE,
	START,
	LOOP,
	CLEAN,
	FAIL,
	EXIT
};

App* app = NULL;

int main(int argc, char* args[])
{
	LOG("Engine starting ...");

	MainState state = CREATE;
	int result = EXIT_FAILURE;

	while(state != EXIT)
	{
		switch(state)
		{
			// Allocate the engine --------------------------------------------
			case CREATE:
			LOG("CREATION PHASE ===============================");

			app = new App(argc, args);

			if(app != NULL)
				state = AWAKE;
			else
				state = FAIL;

			break;

			// Awake all modules -----------------------------------------------
			case AWAKE:
			LOG("AWAKE PHASE ===============================");
			if(app->Awake() == true)
				state = START;
			else
			{
				LOG("ERROR: Awake failed");
				state = FAIL;
			}

			break;

			// Call all modules before first frame  ----------------------------
			case START:
			LOG("START PHASE ===============================");
			if(app->Start() == true)
			{
				state = LOOP;
				LOG("UPDATE PHASE ===============================");
			}
			else
			{
				state = FAIL;
				LOG("ERROR: Start failed");
			}
			break;

			// Loop all modules until we are asked to leave ---------------------
			case LOOP:
			if(app->Update() == false)
				state = CLEAN;
			break;

			// Cleanup allocated memory -----------------------------------------
			case CLEAN:
			LOG("CLEANUP PHASE ===============================");
			if(app->CleanUp() == true)
			{
				RELEASE(app);
				result = EXIT_SUCCESS;
				state = EXIT;
			}
			else
				state = FAIL;

			break;

			// Exit with errors and shame ---------------------------------------
			case FAIL:
			LOG("Exiting with errors :(");
			result = EXIT_FAILURE;
			state = EXIT;
			break;
		}
	}

	LOG("... Bye! :)\n");

	// Dump memory leaks
	return result;
}