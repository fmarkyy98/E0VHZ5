#include <iostream>

using namespace std;

const int MAX_N = 1000;

struct Settlement
{
	double averageMeasurement = 0;
	int maxMeasurement = INT32_MIN;
	int measurements[MAX_N] = { 0 };
};

Settlement settlements[MAX_N];
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

	int index = -1;
	for (int i = 0; i < settlementCount && index == -1; ++i)
	{
		for (int j = 0; j < settlementCount && index == -1; ++j)
		{
			if (i != j && settlements[i].maxMeasurement < settlements[j].averageMeasurement)
			{
				index = i;
			}
		}
	}
	cout << index + 1 << endl;

	return 0;
}
