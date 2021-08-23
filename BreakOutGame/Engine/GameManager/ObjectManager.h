#pragma once

//Object Manager is mainly used for resource/memory management on objects

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

		objects[currentSize] = unique_ptr<Object>(new ObjectType()); //make_unique does not work with abstract class(Object)
		objects[currentSize].get()->SetId(currentSize);
		currentSize++;
		return objects[currentSize - 1].get();
	}

	Object* GetObject(uint32_t id) const;

	void DeleteObject(uint32_t id);

private:

	uint32_t currentSize;
	unique_ptr<Object> objects[1024];
};

