#include  <iostream>
#include <Windows.h>




int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	system("cls");


	while (true)
	{
		std::string fruitDrink[4]{ "Яблочный", "Апельсиновый", "Абрикосовый" , "Грушевый" };
		std::string vegDrink[3]{ "Томатный",  "Луковый", "Огуречный" };
		std::string tea[2]{ "Чесночный", "Петрушевый" };
		double fruitDrinkCost = 100;
		double vegDrinkCost = 70;
		double teaCost = 80;
		int choice = 0;
		int amount = 0;
		double sumForDiscount = 700;
		int petrTea = 0;
		int fruitJuice = 0;
		int boyar_amount = 0;
		double sum = 0;

		while (true)
		{
			std::cout << "\t\t______________________________\n\t\t\t  Соки Даниила\n\t\t______________________________" << std::endl;
			std::cout << "\t\t     Доступный аssортимент\nФруктовые:\n";
			for (int i = 0; i < 4; i++)
			{
				std::cout << i + 1 << ")" << fruitDrink[i] << "(" << fruitDrinkCost << " Рублей)\n";
			}
			std::cout << "\nОвощные:\n";
			for (int i = 4; i < 7; i++)
			{
				std::cout << i + 1 << ")" << vegDrink[i - 4] << "(" << vegDrinkCost << " Рублей)\n";
			}
			std::cout << "\nЧаи:\n";
			for (int i = 7; i < 9; i++)
			{
				std::cout << i + 1 << ")" << tea[i - 7] << "(" << teaCost << " Рублей)\n";
			}
			std::cout << "\nНастойки:\n10)Боярышник(1000 рублей)";
			std::cout << "\n\n(0 - Закончить покупку)" << std::endl;
			std::cout << "Выберите товар: ";
			std::cin >> choice;
			if (choice >= 1 && choice <= 4)
			{
				while (true)
				{
					std::cout << "Введите количество товара: ";
					std::cin >> amount;
					if (amount < 0)
					{
						std::cout << "Некорректный ввод\n";
					}
					else
					{
						break;
					}
				}
				if (amount > 0)
				{
					fruitJuice = 1;
				}
				sum += fruitDrinkCost * amount;
			}
			else if (choice >= 5 && choice <= 7)
			{
				while (true)
				{
					std::cout << "Введите количество товара: ";
					std::cin >> amount;
					if (amount < 0)
					{
						std::cout << "Некорректный ввод\n";
					}
					else
					{
						break;
					}
				}
				if (choice == 6)
				{
					if (amount >= 4)
					{
						int gift = amount / 4;
						amount -= gift;
						sum += vegDrinkCost * amount;
					}
					else
					{
						sum += vegDrinkCost * amount;
					}
				}
				else
				{
					sum += vegDrinkCost * amount;
				}
			}

			else if (choice == 9)
			{
				while (true)
				{
					std::cout << "Введите количество товара: ";
					std::cin >> amount;
					if (amount < 0)
					{
						std::cout << "Некорректный ввод\n";
					}
					else
					{
						break;
					}
				}
				if (amount >= 3)
				{
					sum += (teaCost - (teaCost * 0.05)) * amount;
					petrTea = 1;
				}
				else
				{
					sum += teaCost * amount;
				}
			}
			else if (choice == 8)
			{
				while (true)
				{

					if (amount < 0)
					{
						std::cout << "Некорректный ввод\n";
					}
					else
					{
						break;
					}
				}
				sum += teaCost * amount;
			}
			else if (choice == 0)
			{
				system("cls");
				break;
			}
			else if (choice == 10)
			{
				while (true)
				{
					if (fruitJuice == 1)
					{
						std::cout << "Нельзя";
						Sleep(500);
						break;
					}
					std::cout << "Введите количество товара: ";
					std::cin >> boyar_amount;
					if (boyar_amount < 0)
					{
						std::cout << "Некорректный ввод\n";
					}
					else
					{
						break;
					}
				}

			}

			else
			{
				std::cout << "Некорректный ввод. Повторите попытку\n";
				Sleep(500);
			}
			if (fruitJuice == 1 && boyar_amount > 0)
			{
				std::cout << "\nБоярышник анулирован\n";
				boyar_amount = 0;
				Sleep(500);
			}

			Sleep(500);
			system("cls");



		}


		sum += boyar_amount * 1000;
		if (petrTea == 1)
		{
			std::cout << "Применена скидка 5% на петрушевый чай\n";
		}
		if (sum > sumForDiscount)
		{
			sum = sum - (sum * 0.13);
			std::cout << "Применена скидка 13% на весь чек\n";
		}

		std::cout << "Итоговая стоимость - " << sum << " рублей\n";
		Sleep(1500);
		std::cout << "Принять следующего клиента?(1 - Да, 0 - Нет): ";
		std::cin >> choice;
		if (choice == 0)
		{
			std::cout << "Работа программы завершена";
			break;
		}
		else
		{
			system("cls");
			continue;
		}


	}




}



/*

добавить категорию Настойка: боярышник
Если пользователь купит хотя бы 1 литр фруктового сока, то покупка боярышника блокируется
Если уже боярышник был куплен, то после покупки сока, боярышник анулируется



kолл
g
*/

