#include <iostream>

using namespace std;

struct Settlement
{
	double averageMeasurement = 0;
	int maxMeasurement;
	int measurements[1000];
};

Settlement settlements[1000];
int settlementCount, measurementCount;

int main()
{
	cin >> settlementCount >> measurementCount;
	for (int i = 0; i < settlementCount; ++i)
	{
		for (int j = 0; j < measurementCount; ++j)
		{
			cin >> settlements[i].measurements[j];
		}
	}

	for (int i = 0; i < settlementCount; ++i)
	{
		settlements[i].maxMeasurement = settlements[i].measurements[0];
		for (int j = 1; j < measurementCount; ++j)
		{
			if (settlements[i].measurements[j] > settlements[i].maxMeasurement)
			{
				settlements[i].maxMeasurement = settlements[i].measurements[j];
			}
		}
	}

	for (int i = 0; i < settlementCount; ++i)
	{
		for (int j = 0; j < measurementCount; ++j)
		{
			settlements[i].averageMeasurement += settlements[i].measurements[j];
		}
		settlements[i].averageMeasurement /= measurementCount;
	}



	return 0;
}
//3 5
//10 15 12 10 10
//11 11 11 11 20
//18 16 12 16 20
