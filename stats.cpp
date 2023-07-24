#include "stats.h"
#include <algorithm>
#include <functional>
#define CUSTOM_NAN (std::numeric_limits<double>::quiet_NaN())

Statistics::Stats Statistics::ComputeStatistics(const std::vector<double>& vec) {
	Statistics::Stats stats;

	if (vec.empty())
	{
		stats.average = CUSTOM_NAN;
		stats.max = CUSTOM_NAN;
		stats.min = CUSTOM_NAN;
	}
	else
	{
		stats.average = stats.Average(vec);
		stats.max = stats.Maximum(vec);
		stats.min = stats.Minimum(vec);
	}
	return stats;
}

Statistics::Stats::Stats() :average(0.0), max(0.0), min(0.0)
{
}

double Statistics::Stats::Average(const std::vector<double>& vec)
{
	double avg = 0.0;
	double sum = 0.0;

	for (auto x : vec)
	{
		sum += x;
	}

	avg = sum / double(vec.size());
	return avg;
}

double Statistics::Stats::Maximum(const std::vector<double>& vec)
{
	double maxele = 0;

	maxele = *std::max_element(vec.begin(), vec.end());
	return maxele;
}

double Statistics::Stats::Minimum(const std::vector<double>& vec)
{
	double minele = 0;

	minele = *std::min_element(vec.begin(), vec.end());
	return minele;
}

EmailAlert::EmailAlert() :emailSent(false)
{
}

bool EmailAlert::alert(bool alerSignal)
{
	emailSent = alerSignal;
	return emailSent;
}

LEDAlert::LEDAlert() :ledGlows(false)
{
}

bool LEDAlert::alert(bool alertSignal)
{
	ledGlows = alertSignal;
	return alertSignal;
}

StatsAlerter::StatsAlerter(double maxThreshold, std::vector<IAlerter*> Alerters)
{
	this->maxThreshold = maxThreshold;
	this->alerters = Alerters;
}

void StatsAlerter::checkAndAlert(const std::vector<double>& vec)
{

	for (auto x : vec)
	{
		if (x > maxThreshold)
		{
			alerters[0]->alert(true);
			alerters[1]->alert(true);
		}
	}
}

IAlerter::~IAlerter()
{
}

