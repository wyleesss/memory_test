#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

class VectorClass
{
private:

	vector<int> numbers;

public:

	VectorClass() {}

	int operator[](int index)
	{
		return numbers[index];
	}

	int vec_size()
	{
		return numbers.size();
	}

	VectorClass(int vector_size)
	{
		numbers.resize(12);
		for (auto& i : numbers)
			i = rand() % 90 + 10;
	}

	void cout_12_elements()
	{
		for (int i = 0; i < 12; i++)
		{
			if (i % 4 == 0)
				cout << endl;
			Sleep(1600);
			cout << numbers.at(i) << " ";
		}
		Sleep(1600);
	}

	void edit_12_elements()
	{
		if (numbers.size() < 12)
			numbers.resize(12);
		for (int i = 0; i < 12; i++)
		{
			cout << "[" << i + 1 << "] = ";
			cin >> numbers[i];
		}
	}

	int compare_12_elements(VectorClass& comparing_object)
	{
		int solution = 0;

		if (comparing_object.vec_size() < 12)
			return solution;

		for (int i = 0; i < 12; i++)
			if (comparing_object[i] == numbers[i])
				solution++;

		return solution;
	}

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	cout << "Увага! Вам потрібно буде запам'ятати з 12 чисел якомога більше\nта згодом ввести їх заново в такому ж порядку\n";
	VectorClass first(12);
	first.cout_12_elements();
	system("cls");
	cout << "Тепер введіть якомога більше чисел заново\n";
	VectorClass second;
	second.edit_12_elements();
	cout << first.compare_12_elements(second) << " правильних чисел!";
}
