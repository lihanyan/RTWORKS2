#include<iostream>
using namespace std;

bool carIn = 0, carOut = 0;
bool  light = 0;
bool gateOn = 0;

bool gateOpen()
{
	cout << "杆上升......" << endl;
	gateOn = 1;
	return gateOn;
}

bool gateClose()
{
	cout << "杆下降......" << endl;
	gateOn = 0;
	return gateOn;
}

void lightOn()
{
	cout << "--------------------------绿灯,请通行------------------------" << endl;
	light = 1;
}

void lightOff()
{
	cout << "-----------------------红灯，禁止通行--------------------------" << endl;
	light = 0;
}

int main()
{
	while (1)
	{
		cout << "是否有车进入：";
		cin >> carIn;
		if (carIn == 1)
		{
			if (gateOpen()) 		lightOn();
		}

		while (light)
		{
			cout << "车是否离开：";
			cin >> carOut;
			if (carOut == 1)
			{
				if (!gateClose()) 		lightOff();
			}
		}
	}
	return 0;
}