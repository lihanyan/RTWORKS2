#include<iostream>
using namespace std;

bool carIn = 0, carOut = 0;
bool  light = 0;
bool gateOn = 0;

bool gateOpen()
{
	cout << "������......" << endl;
	gateOn = 1;
	return gateOn;
}

bool gateClose()
{
	cout << "���½�......" << endl;
	gateOn = 0;
	return gateOn;
}

void lightOn()
{
	cout << "--------------------------�̵�,��ͨ��------------------------" << endl;
	light = 1;
}

void lightOff()
{
	cout << "-----------------------��ƣ���ֹͨ��--------------------------" << endl;
	light = 0;
}

int main()
{
	while (1)
	{
		cout << "�Ƿ��г����룺";
		cin >> carIn;
		if (carIn == 1)
		{
			if (gateOpen()) 		lightOn();
		}

		while (light)
		{
			cout << "���Ƿ��뿪��";
			cin >> carOut;
			if (carOut == 1)
			{
				if (!gateClose()) 		lightOff();
			}
		}
	}
	return 0;
}