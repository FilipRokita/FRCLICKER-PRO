//FRCLICKER PRO
//Release 1.0
//Filip Rokita
//filiprokita.com

#include <iostream>
#include <Windows.h>

using namespace std;

char enable, disable;
int cps;
string status = "DISABLED";

void menu()
{
	cout << "ENABLE: "; cin >> enable;
	cout << "DISABLE: "; cin >> disable;
	cout << "CPS: "; cin >> cps;
}

void statusindicator()
{
	system("cls");
	cout << "ENABLE: " << enable << endl;
	cout << "DISABLE: " << disable << endl;
	cout << "CPS: " << cps << endl;
	cout << "STATUS: " << status << endl;
}

void autoclicker()
{
	bool autoclicker = false;
	while (true)
	{
		if (GetAsyncKeyState(enable))
		{
			autoclicker = true;
			status = "ENABLED";
			statusindicator();
		}
		if (GetAsyncKeyState(disable))
		{
			autoclicker = false;
			status = "DISABLED";
			statusindicator();
		}
		if (autoclicker == true)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(1000 / cps);
		}
	}
}

int main()
{
	system("title FRCLICKER PRO - Release 1.0 - filiprokita.com");
	menu();
	autoclicker();
	return 0;
}