#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	currentSize = 0;
}

Object* ObjectManager::GetObject(uint32_t id) const
{
	if (id >= currentSize || id < 0)
	{
		cout << "[ObjectManager] : ID " << id << " is invalid for accessing!" << endl;
		return nullptr;
	}

	return objects[id].get();
}

void ObjectManager::DeleteObject(uint32_t id)
{
	if(id >= currentSize || id < 0)
	{
		cout << "[ObjectManager] : ID " << id << " is invalid for deleting!" << endl;
		return;
	}

	//Deallocate the corresponding object
	objects[id].reset();

	if(currentSize != 0)
	{
		objects[id].swap(objects[currentSize - 1]);
		objects[id].get()->SetId(id);
		currentSize--;
	}
	
}