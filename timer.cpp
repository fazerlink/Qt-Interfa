#include "timer.h"

Timer::Timer()
{
}
Timer::~Timer()
{
}

void Timer::start()
{
  timeOfStart = clock();
}

double Timer::stop()
{
    double endof = clock();
    double time ;
	time = (endof - timeOfStart) / 60;
	this->timeOfStop = time;
	return   time;
}
