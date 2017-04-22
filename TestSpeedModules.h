#ifndef DOXYCRAFT_TESTSPEEDMODULES_H
#define DOXYCRAFT_TESTSPEEDMODULES_H

#include <time.h>

namespace doxyCraft
{
	class TestSpeedModules
	{
	public:
		TestSpeedModules() noexcept;
		
		inline void startTestSpeed() noexcept
		{
			time = clock();
		}
		
		inline clock_t endTestSpeed() noexcept
		{
			returnTime = clock();
			if( returnTime == -1 || time == -1 )
			{
				return -1;
			}
			returnTime -= time;
			time       = 0;
			return returnTime;
		}
	
	private:
		clock_t time;
		clock_t returnTime;
	};
}


#endif //DOXYCRAFT_TESTSPEEDMODULES_H
