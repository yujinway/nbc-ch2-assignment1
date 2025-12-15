#include <iostream>

using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;
	*p_MPPotion = count;
}

void addPotion(int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion += 1;
	*p_MPPotion += 1;
}

int main()
{
	int stat[4] = {}; //HP, MP, 공격력, 방어력
	int level = 1;

	while (true)
	{
		cout << "HP와 MP를 입력해주세요: ";
		cin >> stat[0] >> stat[1];
		if (stat[0] <= 50 || stat[1] <= 50)
		{
			cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
			continue;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		cout << "공격력과 방어력을 입력해주세요: ";
		cin >> stat[2] >> stat[3];
		if (stat[2] <= 0 || stat[3] <= 0)
		{
			cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
			continue;
		}
		else
		{
			break;
		}
	}

	int HPPotion = 0, MPPotion = 0;
	int choice;

	setPotion(5, &HPPotion, &MPPotion);

	cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
	cout << "=============================================" << endl;
	cout << "<스탯 관리 시스템>" << endl;
	cout << "1. HP UP\n2. MP UP\n3. 공격력 UP\n4. 방어력 UP\n5. 현재 능력치\n6. Level UP\n0. 나가기" << endl;

	while (true)
	{
		cout << "번호를 선택해주세요: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (HPPotion > 0)
			{
				stat[0] += 20;
				HPPotion -= 1;
				cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
				cout << "현재 HP: " << stat[0] << "\n남은 포션 수: " << HPPotion << endl;
				break;
			}
			else
			{
				cout << "포션이 부족합니다." << endl;
				break;
			}

		case 2:
			if (MPPotion > 0)
			{
				stat[1] += 20;
				MPPotion -= 1;
				cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
				cout << "현재 MP: " << stat[1] << "\n남은 포션 수: " << MPPotion << endl;
				break;
			}
			else
			{
				cout << "포션이 부족합니다." << endl;
				break;
			}

		case 3:
			stat[2] *= 2; //stat[2] = stat[2] << 1;
			cout << "공격력이 2배로 증가되었습니다." << endl;
			break;

		case 4:
			stat[3] *= 2; //stat[3] = stat[3] << 1;
			cout << "방어력이 2배로 증가되었습니다." << endl;
			break;

		case 5:
			cout << "* 현재 레벨: " << level << " HP : " << stat[0] << " MP : " << stat[1] << " 공격력 : " << stat[2] << " 방어력 : " << stat[3] << endl;
			cout << "* 남은 HP 포션 수: " << HPPotion << " 남은 MP 포션 수: " << MPPotion << endl;
			break;

		case 6:
			level += 1;
			addPotion(&HPPotion, &MPPotion);
			cout << "* 레벨업! HP/MP 포션이 지급됩니다." << endl;
			break;

		case 0:
			cout << "프로그램을 종료합니다.";
			return 0;

		default:
			cout << "번호가 잘못되었습니다. 다시 입력해주세요." << endl;
			break;
		}
	}

	return 0;
}