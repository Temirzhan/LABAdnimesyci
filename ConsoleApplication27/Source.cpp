#include<locale.h>
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<math.h>

using namespace std;
int getCountDayMonth(int god, int month);
int isLeap(int god);
int getPastDay(int god, int month, int day);
int getNextDay(int god, int month, int day);
int visokos(int god);
void main()
{
	setlocale(LC_ALL, "rus");
	/*���� ���������� ��� ��������������� ����� ������������ �������: g (���), m (���������� ����� ������) � n (�����). �� �������� g, n � m ���������� (���������� �������, �������������� ���������� ���� � ��� ��� ���� ������):
���� ����������� ���;
���� ���������� ���
� ����� ������� ����������� ��� ������:
�������� ��� �� �������� ����������; 
�������� ��� ����� ���� ����������
*/
	int god;
	cout << "������� ���" << endl;
	cin>>god;
	int month;
	cout << "������� �����" << endl;
	cin >> month;
	cout << "����������� ���� � ������ = " << getCountDayMonth(god, month) << endl;
	cout << "----------------------------" << endl;
	int day;
	cout << "������� ���� ����� ������" << endl;
	cin >> day;
    getPastDay( god,  month,  day);
	getNextDay(god,month, day);

}

int isLeap(int god)
{
	if (((god % 4) == 0) || ((god % 400) == 0) && ((god % 100) != 0))
		return 1;

	return 0;
}

int getCountDayMonth(int god, int month)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if (isLeap(god))
			return 29;
		else
			return 28;
		break;
	default:
		return 0;

	}
}
int getPastDay(int god, int month, int day)
{
	if (day == 1)
	{
	if (month == 1)
	{
		god--;
		month = 12;
		day = getCountDayMonth(god, month);
	}
	else
	{
		month--;
		day = getCountDayMonth(god, month);
	}
	}

	else
	{
		day--;
	}
	cout <<"��������� ���� " << day << "." << month << "." << god ;
	visokos(god);
	return 0;
}

int getNextDay(int god, int month, int day)
{
	if (day == getCountDayMonth(god, month))
	{
		if (month == 12)
		{
			god++;
			month = 1;
		}
		else
		{
			month++;
		}
		day = 1;
	}
	else
	{
			day++;
	}
	cout << "���������� ���� " << day << "." << month << "." << god ;
	visokos(god);
	return 0;
}

int visokos(int god)
{
	if (isLeap(god) == 1)
		cout << " ����������" << endl;

	else cout << " �� ����������" << endl;
	return 0;
}



		

