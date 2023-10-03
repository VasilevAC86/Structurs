# include <iostream>
#include <string>

struct  Date {
	int day = 1;
	int month = 1;
	int year = 1970;
	std::string note = "empty";
};

void print_date(const Date& D) {
	std::cout << D.day << '.' << D.month << '.' << D.year << " - " << D.note << std::endl;
}

Date input_date() {
	Date tmp;
	std::cout << "Введите день -> ";
	std::cin >> tmp.day;
	std::cout << "Введите месяц -> ";
	std::cin >> tmp.month;
	std::cout << "Введите год -> ";
	std::cin >> tmp.year;
	std::cin.ignore();
	std::cout << "Введите запись -> ";
	std::getline(std::cin, tmp.note);
	return tmp;
}

void fill_date(Date& D) {
	std::cout << "Введите день -> ";
	std::cin >> D.day;
	std::cout << "Введите месяц -> ";
	std::cin >> D.month;
	std::cout << "Введите год -> ";
	std::cin >> D.year;
	std::cin.ignore();
	std::cout << "Введите запись -> ";
	std::getline(std::cin, D.note);
}

struct my_Date {
	int day = 1;
	int month = 1;
	int year = 1970;
};

struct CoinKeeper {
	std::string name = "noname";
	my_Date birtday;
	int coins_number = 0;
	int* coins = nullptr;
};

void print_keeper(const CoinKeeper& CK) {
	std::cout << "Name: " << CK.name << std::endl;
	std::cout << "BirthDay: " << CK.birtday.day << '.' << CK.birtday.month << '.' << CK.birtday.year << std::endl;
	std::cout << "Coins: ";
	for (short i = 0; i < CK.coins_number; i++)
		std::cout << CK.coins[i]<<' ';
}

inline int age(const CoinKeeper& CK, int year) {
	return (year - CK.birtday.year);
}

int cash(const CoinKeeper& CK) {
	int sum = 0;
	for (int i = 0; i < CK.coins_number; i++)
		sum += CK.coins[i];
	return sum;
}

struct Point {
	double X{};
	double Y{};
};

int compere_Distance(Point P1, Point P2) {
	double dist1 = P1.X * P1.X + P1.Y * P1.Y;
	double dist2 = P2.X * P2.X + P2.Y * P2.Y;
	if (dist1 > dist2)
		return 1;
	return dist1 < dist2 ? -1 : 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Структуры: создание, мгновенная инициализация и работа с полями
	struct Person {
		std::string name;
		short age;
		std::string job;
		double salary;
	} p3, p4{"Unknown person", 18};
	Person p1; // Создание объекта на основе структуры Person
	// Инициализация полей объекта p1
	p1.name = "Tom Smith";
	p1.age = 25;
	p1.job = "programmer";
	p1.salary = 80000;
	// Вывод полей объекта p1
	std::cout << "Имя: " << p1.name << std::endl;
	std::cout << "Возраст: " << p1.age << std::endl;
	std::cout << "Должность: " << p1.job << std::endl;
	std::cout << "Зарплата: " << p1.salary << std::endl;

	Person p2{
		"Bob Thomas", 
		45,
		"director",
		130000
	};
	std::cout << "--------------------------------" << std::endl;
	// Вывод полей объекта p2
	std::cout << "Имя: " << p2.name << std::endl;
	std::cout << "Возраст: " << p2.age << std::endl;
	std::cout << "Должность: " << p2.job << std::endl;
	std::cout << "Зарплата: " << p2.salary << std::endl;

	p3 = p1; // Копирование значений полей объекта p1 в поля объекта p3

	// Указатели и функции при работе со структурами
	Date d1;
	print_date(d1);

	Date* pd1 = &d1;
	std::cout << pd1 << std::endl;
	std::cout << "День: " << pd1->day << std::endl; // Обращение к полю day через указатель на объект d1
	std::cout << std::endl;
	std::cout << "Ввод данных в объект:\n";
	//Date d2 = input_date();
	Date d2;
	fill_date(d2);
	print_date(d2);

	// Задача 1. Структура CoinKeeper (Хранитель монет)
	std::cout << "Task 1.\n\n";
	CoinKeeper ck{
		"Robert Polson",
		{ 17, 10, 1986 },
		5,
		new int[5] { 10, 5, 2, 1, 1 }
	};
	print_keeper(ck);
	std::cout << std::endl;
	std::cout << "The age: " << age(ck, 2023) << std::endl;
	std::cout << "The sum = " << cash(ck) << std::endl;
	delete[] ck.coins; // освобождаем память, выделенную под динамический массив

	// Задача 2. Расстояния до точек
	std::cout << "Task 2\n";
	Point A{ 2.2, 5.0 }, B{ 7.1, 6.8 };
	std::cout << compere_Distance(A, B) << std::endl;
	
	return 0;
}