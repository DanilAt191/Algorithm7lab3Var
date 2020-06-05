#include <iostream>
#include <stack>
#include <time.h>

using namespace std;

void easy() //Создать стек из N целых чисел. Вывести указатель на его последний элемент;
{
	stack <int> Numbers;
	int* P1, N;

	do
	{
		cout << "Введите кол-во элементов стека(>0): ";
		cin >> N;
		cout << endl;
	} while (N <= 0);

	cout << "Стек целых чисел: ";
	for (int i = 0; i < N; i++)
	{
		Numbers.push(rand() % 10);
		cout << Numbers.top() << " ";
	}

	P1 = &Numbers.top();

	cout << endl << "Вершина стека: " << *P1 << endl << endl;
}

void medium()//Заполнить стек строковыми значениями. Удалить элемент стека и добавить новый. Посчитать кол-во двусимвольных строк стека;
{
	stack <string> Words;

	Words.push("abc");
	Words.push("fx");
	Words.push("glc");
	Words.push("hi");
	Words.push("gogo");

	string arr[5];
	int count = 0;

	
	cout << "Элементы стека: ";
	for (int i = 0; i < 5; i++)
	{
		cout << Words.top() << " ";
		arr[i] = Words.top();
		Words.pop();
	}

	for (int i = 0; i < 5; i++)
	{
		Words.push(arr[i]);
	}

	
	cout << endl;

	Words.pop();
	Words.push("the_end");

	cout << "Стек после изменений: ";
	for (int i = 0; i < 5; i++)
	{
		cout << Words.top() << " ";
		if (Words.top().length() == 2)
			count++;
		Words.pop();
	}

	cout << endl << "Кол-во двусимвольных строк: " << count << endl << endl;
}

void hard() //Дана строка скобок. Выяснить, является ли данная строка правильной(кол-во закрывающих и открывающих скобок совпадает). Добавить и считать из стека открывающие скобки;
			//Вывести все скобки на экран;
{

	stack <char> Stack;
	const int size = 8;
	char arr[size] = { ')','}','[','[',']','(','{',']' };
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == '(')
		{
			Stack.push(arr[i]);
			count1++;
		}
		if (arr[i] == '{')
		{
			Stack.push(arr[i]);
			count2++;
		}
		if (arr[i] == '[')
		{
			Stack.push(arr[i]);
			count3++;
		}
		if (arr[i] == ')')
		{
			count4++;
		}
		if (arr[i] == '}')
		{
			count5++;
		}
		if (arr[i] == ']')
		{
			count6++;
		}
	}

	cout << "Открывающие скобки: ";

	do
	{
		cout << Stack.top() << " ";
		Stack.pop();
	} while (!Stack.empty());

	cout << endl;

	cout << "Закрывающие скобки: ";

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}')
		{
			cout << arr[i] << " ";
		}
	}

	cout << endl;

	if (count1 == count4 && count2 == count5 && count3 == count6)
	{
		cout << "Строка правильная";
	}
	else
	{
		cout << "Строка не правильная";
	}

	cout << endl << endl;
};


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RU");

	int a;
	int count = 0;

	do
	{
		cout << "Введите номер задания(easy - 1, medium - 2, hard - 3): ";

		cin >> a;

		cout << endl;

		if (a == 1)
		{
			easy();
			count++;
		}

		if (a == 2)
		{
			medium();
			count++;
		}

		if (a == 3)
		{
			hard();
			count++;
		}

	} while (count == 0);

	int b;

	do
	{
		count = 0;

		cout << "Продолжить ввод? Да - 1, Нет - 2: ";

		cin >> b;

		cout << endl;

		if (b == 1)
		{
			count++;
			main();
		}

		if (b == 2)
		{
			cout << "Вы решили не продолжать";
			count++;
			break;
		}

	} while (count == 0);
}