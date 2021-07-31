#pragma once

using namespace std;

template<class T>
class GameSingleton
{
public:

	static T& GetInstance()
	{
		static T instance; 
		return instance;
	}

	GameSingleton() {}

	//No copies
	GameSingleton(GameSingleton const&) = delete;
	void operator=(GameSingleton const&) = delete;

};

