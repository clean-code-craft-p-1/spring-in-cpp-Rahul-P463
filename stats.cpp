#include "pch.h"
#include "stats.h"

#include <functional>

Statistics::Stats Statistics::ComputeStatistics(const std::vector<double>& vec) {
	Statistics::Stats stats;

	if (vec.empty())
	{
		stats.average = std::nan("");
		stats.max = std::nan("");
		stats.min = std::nan("");
	}
	else
	{
		stats.average = stats.Average(vec);
		stats.max = stats.Maximum(vec);
		stats.min = stats.Minimum(vec);
	}
	return stats;
}

double Statistics::Stats::Average(const std::vector<double>& vec)
{
	double avg = 0.0;
	double sum = 0.0;

	for (auto x : vec)
	{
		sum += x;
	}

	avg = sum / vec.size();
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

bool EmailAlert::alert(bool alerSignal)
{
	emailSent = alerSignal;
	return emailSent;
}

bool LEDAlert::alert(bool alertSignal)
{
	ledGlows = alertSignal;
	return alertSignal;
}

StatsAlerter::StatsAlerter(double maxThreshold, std::vector<IAlerter*> alerters)
{
	this->maxThreshold = maxThreshold;
	this->alerters = alerters;
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
