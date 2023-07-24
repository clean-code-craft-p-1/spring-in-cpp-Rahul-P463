#include <vector>

namespace Statistics {
	// define the Stats structure here. See the tests to infer its properties
	struct Stats
	{
		double average;
		double max;
		double min;

		Stats() :average(0.0), max(INT_MIN), min(INT_MAX)
		{

		}

		double Average(const std::vector<double>&);
		double Maximum(const std::vector<double>&);
		double Minimum(const std::vector<double>&);
	};

	Stats ComputeStatistics(const std::vector<double>&);
}

class IAlerter
{
public:
	virtual bool alert(bool) = 0;
};

class EmailAlert : public IAlerter
{
public:
	EmailAlert() :emailSent(false)
	{

	}

	bool emailSent;

	bool alert(bool alerSignal);
};

class LEDAlert : public IAlerter
{
public:
	LEDAlert() :ledGlows(false)
	{

	}

	bool ledGlows;

	bool alert(bool alertSignal);
};


class StatsAlerter
{
	std::vector<IAlerter*> alerters;
	double maxThreshold;

public:
	StatsAlerter(double maxThreshold, std::vector<IAlerter*> alerters);

	void checkAndAlert(const std::vector<double>&);
};
