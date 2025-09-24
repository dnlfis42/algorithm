#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str1, str2, str3;
	cin >> str1 >> str2 >> str3;

	if (str1.compare("FizzBuzz") == 0)
	{
		cout << "Fizz";
	}
	else if (str1.compare("Fizz") == 0)
	{
		if (str2.compare("Buzz") == 0)
		{
			cout << "Fizz";
		}
		else
		{
			if ((stoi(str2) + 2) % 5 == 0)
			{
				cout << "FizzBuzz";
			}
			else
			{
				cout << "Fizz";
			}
		}
	}
	else if (str1.compare("Buzz") == 0)
	{
		if (str2.compare("Fizz") == 0)
		{
			cout << stoi(str3) + 1;
		}
		else
		{
			cout << stoi(str2) + 2;
		}
	}
	else // 일단 절대 3의 배수는 아님
	{
		if ((stoi(str1) + 3) % 5 == 0)
		{
			cout << "Buzz";
		}
		else
		{
			cout << stoi(str1) + 3;
		}
	}

	return 0;
}