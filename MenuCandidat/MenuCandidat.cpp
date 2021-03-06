#include "stdafx.h"

#define VK_ESCAPE 27
#define VK_UP     72
#define VK_DOWN   80
#define VK_LEFT   75
#define VK_RIGHT  77
#define VK_RETURN 13

#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int ch;

	do
	{
		ch = _getch();
		cout << ch << " first" << endl;
		if (ch == 0 || ch == 224)
		{
			ch = _getch();
			cout << ch << " second" << endl;
			switch (ch)
			{
			case VK_UP:
				cout << "Up=" << ch << endl;
				break;

			case VK_DOWN:
				cout << "DOWN=" << ch << endl;
				break;

			case VK_LEFT:
				cout << "LEFT=" << ch << endl;
				break;

			case VK_RIGHT:
				cout << "RIGHT=" << ch << endl;
				break;

			default:
				cout << ch << " is not a valid menu item. 1" << endl;
			}
		}
		else
		{
			switch (ch)
			{
			case VK_RETURN:
				cout << "2 RETURN=" << ch << endl;
				break;

			default:
				cout << ch << " is not a valid menu item. 2" << endl;
			}
		}
	}
	while (ch != VK_ESCAPE);

	_sleep(2000);
    return 0;
}

