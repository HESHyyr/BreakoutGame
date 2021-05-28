#pragma once
class GameComponent
{

public:

	void SetActive(bool active) { isActive = active; }
	virtual void DestroySelf() = 0;

protected:

	bool isActive;

};