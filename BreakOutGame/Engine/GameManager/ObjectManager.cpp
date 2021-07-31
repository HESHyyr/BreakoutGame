#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	currentSize = 0;
}

Object* ObjectManager::GetObject(uint32_t id) const
{
	if (id >= currentSize || id < 0)
	{
		cout << "[ObjectManager] : ID is invalid for accessing!" << endl;
		return nullptr;
	}

	return objects[id];
}

void ObjectManager::DeleteObject(uint32_t id)
{
	if(id >= currentSize || id < 0)
	{
		cout << "[ObjectManager] : ID is invalid for deleting!" << endl;
		return;
	}

	//Deallocate the corresponding object
	delete objects[id];

	if(currentSize != 0)
	{
		objects[id] = objects[currentSize - 1];
		objects[id]->SetId(id);
		currentSize--;
	}
	
}