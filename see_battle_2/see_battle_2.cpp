
#include <iostream>
using namespace std;

void init_map(char map[][11], int row, int cols) {
	map[0][0] = ' ';
	for (int j = 1; j < cols; j++) {
		map[0][j] = 47 + j;
	}
	for (int i = 1; i < row; i++) {
		map[i][0] = 47 + i;
	}
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < cols; j++) {
			map[i][j] = 250;
		}
	}
}
//вывод одного поля
void print_map(char map[][11], int row, int cols) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cols; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
//вывод двых полей
void map_to_map(char my_map[][11], char comp_map[][11], int row, int cols) {
	cout << "\tMy map\t\t\t\     Computer map" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cols; j++) {
			cout << my_map[i][j] << " ";
		}
		cout << "\t\t";
		for (int j = 0; j < cols; j++) {
			cout << comp_map[i][j] << " ";
		}
		cout << endl;
	}
}
//проверка выхода за границы поля
bool test_coordinates(int& x, int& y) {
	bool test;
	(x > 0 && x < 11) && (y > 0 && y < 11) ? test = true : test = false;
	return test;
}
//ввод координат
int& coordinates(int& x, int& y) {
	cout << endl << "enter a coordinates from 1 to 10" << endl;
	while (true){
		cin >> x >> y;
		if (test_coordinates(x, y)) {
			return x, y;
		}
		else {
			cout << "Enter correct coordinat from 1 to 10" << endl;
		}
	}
}
//ввод направления
int& direction(int& dir) {
	cout << "enter direction from 1 to 4" << endl;
	while (true) {
		cin >> dir;
		if (dir > 0 && dir < 5) {
			return dir;
		}
		else {
			cout << "Enter correct direction from 1 to 4" << endl;
		}
	}
}
//проверка координаты
bool test_location(char map[][11], int& x, int& y) {
	bool test;
	if (map[x][y] != 79 &&
		map[x][y + 1] != 79 &&
		map[x + 1][y + 1] != 79 &&
		map[x + 1][y] != 79 &&
		map[x + 1][y - 1] != 79 &&
		map[x][y - 1] != 79 &&
		map[x - 1][y - 1] != 79 &&
		map[x - 1][y] != 79 &&
		map[x - 1][y + 1] != 79) {
		test = true;
	}
	else {
		test = false;
	}
	return test;
}
//рекурсивная отрисовка
//char rec_init(char map[][11], int x, int y, int deck, int i) {
//	 
//		if (i == deck - 1) {
//			if (test_location(map, x, y)) {
//				return map[x][y];
//			}
//			else {
//				return 200;
//			}
//		}
//		else {
//			if (test_location(map, x, y)) {
//				return map[x][y] + rec_init(map, x++, y, deck, i++);
//			}
//			else {
//				return 200;
//			}
//			
//		}
//	
//	
//}

//проверка на возможность отрисовки
bool test_init(char map[][11], int x, int y, int& deck, int& dir) {
	bool test = true;
	for (int i = 0; i < deck; i++) {
		if (test_location(map, x, y) && (test_coordinates(x, y))) {
			if (dir == 0) {
				x++;
			}
			if (dir == 1) {
				y++;
			}
		}
		else {
			test = false;
			break;
		}
	}
	return test;
}
//отрисовка кораблей
void init_ships(char map[][11], int& x, int& y, int& deck, int& dir) {
	if (test_init(map, x, y, deck, dir)) {
		for (int i = 0; i < deck; i++) {
			map[x][y] = 79;
			if (dir == 0) {
				x++;
			}
			if (dir == 1) {
				y++;
			}
		}
	}
	else {
		cout << "You don't install ship" << endl;
	}
}
//ручная расстановка
void location_ships(char map[][11], int row, int cols) {
	int x, y, dir, deck;
	for (int i = 0; i < 10; i++) {
		coordinates(x, y);
		direction(dir);
		system("cls");
		if (test_location(map, x, y) && (test_coordinates(x, y))) {
			if (i == 0) {
				deck = 4;
				init_ships(map, x, y, deck, dir);
				print_map(map, row, cols);
			}
			if (i == 1 || i == 2) {
				deck = 3;
				init_ships(map, x, y, deck, dir);
				print_map(map, row, cols);
			}
			if (i == 3 || i == 4 || i == 5) {
				deck = 2;
				init_ships(map, x, y, deck, dir);
				print_map(map, row, cols);
			}
			if (i == 6 || i == 7 || i == 8 || i == 9) {
				deck = 1;
				init_ships(map, x, y, deck, dir);
				print_map(map, row, cols);
			}
		}
		else {
			cout << "Can't install ship!" << endl;
			i--;
			print_map(map, row, cols);
		}
	}
	system("cls");
}

int main()
{
	const int row = 11,
		cols = 11;
	char my_map[row][cols]{};
	char comp_map[row][cols]{};
	init_map(my_map, row, cols);
	init_map(comp_map, row, cols);
	map_to_map(my_map, comp_map, row, cols);

	location_ships(my_map, row, cols);
	map_to_map(my_map, comp_map, row, cols);


}

//отрисовал карты, выполнил ручную расстановку, условие игры по установке 1 координаты
// 
//добавить 3 и 4 направления для расстановки, валидность координат, отредактировать название координат, доработать ф-ию
// правильной отрисовки кораблей

