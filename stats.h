#include <vector>

namespace Statistics {

	struct Stats
	{
		double average;
		double max;
		double min;

		Stats();

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
	virtual ~IAlerter();
};

class EmailAlert : public IAlerter
{
public:
	bool emailSent;
public:
	EmailAlert();
	bool alert(bool alerSignal) override;
};

class LEDAlert : public IAlerter
{
public:
	bool ledGlows;
public:
	LEDAlert();
	bool alert(bool alertSignal) override;
};


class StatsAlerter
{
private:
	std::vector<IAlerter*> alerters;
	double maxThreshold;

public:
	StatsAlerter(double maxThreshold, std::vector<IAlerter*> alerters);

	void checkAndAlert(const std::vector<double>&);
};

