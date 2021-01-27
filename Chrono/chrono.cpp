#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

void SimpleDurationTypes()
{
	using namespace std::chrono;

	seconds sec{ 12 };
	seconds sec2 = 12s;
	// seconds sec3 = 1200ms; // Error!
	seconds sec4 = std::chrono::duration_cast<seconds>(1200ms); // Ok
	milliseconds ms = 200ms;

	auto duration1 = sec - ms;
	std::cout << "First duration is " << duration1.count() << "ms" << std::endl;

	auto duration2 = hours(1) + minutes(1) + seconds(1) + milliseconds(1);
	std::cout << "Second duration is " << duration2.count() << "ms" << std::endl;

	std::cout << "Seconds max is " << seconds::max().count() << "; min is " << seconds::min().count() << std::endl;
}

void AdvancedDurationType()
{
	using namespace std::chrono;

	using myDuration = duration<long long, std::ratio<1, 15>>;

	auto duration1 = myDuration{ 2 };
	auto duration2 = seconds{ 2 };
	auto durationSum = duration1 + duration2;

	std::cout << "Duration 1   = " << duration1.count() << "; " << duration_cast<milliseconds>(duration1).count() << "ms" << std::endl;
	std::cout << "Duration 2   = " << duration2.count() << "; " << duration_cast<milliseconds>(duration2).count() << "ms" << std::endl;
	std::cout << "Duration Sum = " << durationSum.count() << "; " << duration_cast<milliseconds>(durationSum).count() << "ms" << std::endl;
}

void PrintCurrentTimeDate()
{
	std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(timePoint);

	char timeDateStr[128];
	ctime_s(timeDateStr, 128, &currentTime);
	std::cout << "Current date time is " << timeDateStr;
}

void GetElapsedTime()
{
	using namespace std::chrono;

	system_clock::time_point startTimePoint = system_clock::now();
	std::this_thread::sleep_for(200ms);
	system_clock::time_point endTimePoint = system_clock::now();

	duration<double> elapsedSeconds = endTimePoint - startTimePoint;
	std::cout << "Elapsed time = " << elapsedSeconds.count() << "s\n";
}

void GetUnixTime()
{
	using namespace std::chrono;

	system_clock::time_point currentTimeStamp = system_clock::now();
	auto milliseconds = currentTimeStamp.time_since_epoch();
	auto unixTime = duration_cast<seconds>(milliseconds);
	std::cout << "Unix time is " << unixTime.count() << std::endl;
}

int main()
{
	SimpleDurationTypes();
	AdvancedDurationType();
	PrintCurrentTimeDate();
	GetElapsedTime();
	GetUnixTime();
}
