#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int light;
	cin >> light;
	if (light >= 620)
	{
		cout << "Red";
	}
	else if (light >= 590)
	{
		cout << "Orange";
	}
	else if (light >= 570)
	{
		cout << "Yellow";
	}
	else if (light >= 495)
	{
		cout << "Green";
	}
	else if (light >= 450)
	{
		cout << "Blue";
	}
	else if (light >= 425)
	{
		cout << "Indigo";
	}
	else
	{
		cout << "Violet";
	}

	return 0;
}