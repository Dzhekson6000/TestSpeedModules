#ifndef DOXYCRAFT_TESTSPEEDFINCTIONS_H
#define DOXYCRAFT_TESTSPEEDFINCTIONS_H

#include <utility>
#include "TestSpeedModules.h"

namespace doxyCraft
{
	template<class T, typename... Args>
	clock_t timeCreateObject(Args &&...args)
	{
		auto test = TestSpeedModules();
		test.startTestSpeed();
		T(std::forward<Args...>(args...));
		return test.endTestSpeed();
	};
	
	template<class T>
	clock_t timeCreateObject()
	{
		auto test = TestSpeedModules();
		test.startTestSpeed();
		T();
		return test.endTestSpeed();
	};
	
	template<class T, typename... Args>
	clock_t timeDeleteObject(Args &&...args)
	{
		auto test = TestSpeedModules();
		auto tmp = new T(std::forward<Args...>(args...));
		test.startTestSpeed();
		delete tmp;
		return test.endTestSpeed();
	};
	
	template<class T>
	clock_t timeDeleteObject()
	{
		auto test = TestSpeedModules();
		auto tmp = new T();
		test.startTestSpeed();
		delete tmp;
		return test.endTestSpeed();
	};
}


#endif //DOXYCRAFT_TESTSPEEDFINCTIONS_H
