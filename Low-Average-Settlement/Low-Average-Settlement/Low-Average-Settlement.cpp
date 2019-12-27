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

void safetyReading(int& localSettlementCount, int& localMeasurementCount, Settlement localSettlements[MAX_N])
{
	do
	{
		if (cin.fail())
		{
			cout << "Invalid input value type, restart the input from begining." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cin >> localSettlementCount >> localMeasurementCount;
		for (int i = 0; i < localSettlementCount; ++i)
		{
			for (int j = 0; j < localMeasurementCount; ++j)
			{
				cin >> localSettlements[i].measurements[j];
			}
		}
	} while (cin.fail());
}

void calculateMaxAndAvg(int localSettlementCount, int localMeasurementCount, Settlement localSettlements[MAX_N])
{
	for (int i = 0; i < localSettlementCount; ++i)
	{
		localSettlements[i].maxMeasurement = localSettlements[i].measurements[0];
		for (int j = 1; j < localMeasurementCount; ++j)
		{
			if (localSettlements[i].measurements[j] > localSettlements[i].maxMeasurement)
			{
				localSettlements[i].maxMeasurement = localSettlements[i].measurements[j];
			}
		}
	}

	for (int i = 0; i < localSettlementCount; ++i)
	{
		for (int j = 0; j < localMeasurementCount; ++j)
		{
			localSettlements[i].averageMeasurement += localSettlements[i].measurements[j];
		}
		localSettlements[i].averageMeasurement /= localMeasurementCount;
	}
}

int indexOfLowAverageSettlement(int localSettlementCount, Settlement localSettlements[MAX_N])
{
	int localIndex = -1;
	for (int i = 0; i < localSettlementCount && localIndex == -1; ++i)
	{
		for (int j = 0; j < localSettlementCount && localIndex == -1; ++j)
		{
			if (i != j && localSettlements[i].maxMeasurement < localSettlements[j].averageMeasurement)
			{
				localIndex = i;
			}
		}
	}
	return localIndex;
}

int main()
{
	safetyReading(settlementCount, measurementCount, settlements);

	calculateMaxAndAvg(settlementCount, measurementCount, settlements);

	int index = indexOfLowAverageSettlement(settlementCount, settlements);

	cout << (index != -1 ? index + 1 : -1) << endl;

	return 0;
}
