#pragma once

template<typename T>
class Singleton
{
protected:
	Singleton() {};
	virtual ~Singleton() {};
	Singleton(const Singleton& r) {};
	Singleton& operator=(const Singleton& r) {};

public:
	static T* GetInstance(){
		static T instance;
		return &instance;
	}

};
