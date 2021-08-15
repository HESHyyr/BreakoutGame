#pragma once

#include <memory>
#include <iostream>

#include <GameManager/GameSingleton.h>
#include <Core/CoreClass.h>

using namespace std;

class ObjectManager : public GameSingleton<ObjectManager>
{

public:

	ObjectManager();

	template <typename ObjectType>
	Object* CreateObject()
	{
		if(currentSize >= 1024)
		{
			cout << "[ObjectManager] : Reach Maximum Object Number." << endl;
			return nullptr;
		}

		objects[currentSize] = new ObjectType();
		objects[currentSize]->GetId(currentSize);
		currentSize++;
		return objects[currentSize - 1];
	}

	Object* GetObject(uint32_t id) const;

	void DeleteObject(uint32_t id);

private:

	uint32_t currentSize;
	Object* objects[1024];
};

