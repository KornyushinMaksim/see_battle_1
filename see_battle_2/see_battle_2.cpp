
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
	cout << "\tMy map" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cols; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
//вывод двух полей
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
	if ((x > 0 && x < 11) && (y > 0 && y < 11)) {
		test = true;
	}
	else {
		test = false;
	}
	return test;
}
//ввод координат
int& enter_coordinates(int& x, int& y) {
	cout << endl << "Enter a coordinates from 1 to 10" << endl;
	while (true) {
		cout << "coordinate x: ";
		cin >> x;
		cout << "coordinate y: ";
		cin >> y;
		if (test_coordinates(x, y)) {
			return x, y;
		}
		else {
			cout << "Enter correct coordinat from 1 to 10" << endl;
		}
	}
}
//ввод направления
int& enter_direction(int& dir) {
	//cout << "enter direction from 1 to 4" << endl;
	while (true) {
		cout << "Enter direction from 1 to 4\n1. right\n2. down\n3. left\n4. up" << endl;
		cin >> dir;
		if (dir > 0 && dir < 5) {
			return dir;
		}
		//else {
		//	cout << "Enter correct direction from 1 to 4\n1. right\n2. down\n3. left\n4. up" << endl;
		//}
	}
}
//проверка координаты
bool test_location(char map[][11], int& x, int& y, int& index) { //??????????????????????????????????????????????????????
	bool test = true;						------------
	if (map[x][y] == 250 ||
		map[x][y + 1] == 250 ||
		map[x + 1][y + 1] == 250 
		|| map[x + 1][y] == 250 
		|| map[x + 1][y - 1] == 250 
		|| map[x][y - 1] == 250 
		|| map[x - 1][y - 1] == 250 
		|| map[x - 1][y] == 250
		|| map[x - 1][y + 1] == 250) {
		//test = true;
	}
	else {
		test = false;
	}
	return test;
}
//проверка на возможность отрисовки
bool test_init(char map[][11], int x, int y, int& deck, int& dir, int& index) {
	bool test = true;
	for (int i = 0; i < deck; i++) {
		if (test_location(map, x, y, index) && (test_coordinates(x, y))) {
			if (dir == 1) {
				y++;
			}
			if (dir == 2) {
				x++;
			}
			if (dir == 3) {
				y--;
			}
			if (dir == 4) {
				x--;
			}
		}
		else {
			test = false;
			break;
		}
	}
	return test;
}
//обрисовка
void edging_ship(char map[][11],int& x, int& y, int& index) {
	if (map[x][y] == 48 + index) {
		if (y == 10) {
			if (map[x + 1][y] != 48 + index) {
				map[x + 1][y] = 42;
			}
			else {
				map[x + 1][y] = 48 + index;
			}
			if (map[x + 1][y - 1] != 48 + index) {
				map[x + 1][y - 1] = 42;
			}
			else {
				map[x + 1][y - 1] = 48 + index;
			}
			if (map[x][y - 1] != 48 + index) {
				map[x][y - 1] = 42;
			}
			else {
				map[x][y - 1] = 48 + index;
			}
			if (map[x - 1][y - 1] != 48 + index) {
				map[x - 1][y - 1] = 42;
			}
			else {
				map[x - 1][y - 1] = 48 + index;
			}
			if (map[x - 1][y] != 48 + index) {
				map[x - 1][y] = 42;
			}
			else {
				map[x - 1][y] = 48 + index;
			}
		}
		else if (y == 1) {
			if (map[x][y + 1] != 48 + index) {
				map[x][y + 1] = 42;
			}
			else {
				map[x][y + 1] = 48 + index;
			}
			if (map[x + 1][y + 1] != 48 + index) {
				map[x + 1][y + 1] = 42;
			}
			else {
				map[x + 1][y + 1] = 48 + index;
			}
			if (map[x + 1][y] != 48 + index) {
				map[x + 1][y] = 42;
			}
			else {
				map[x + 1][y] = 48 + index;
			}
			if (map[x - 1][y] != 48 + index) {
				map[x - 1][y] = 42;
			}
			else {
				map[x - 1][y] = 48 + index;
			}
		}
		else if (x == 1) {
			if (map[x][y + 1] != 48 + index) {
				map[x][y + 1] = 42;
			}
			else {
				map[x][y + 1] = 48 + index;
			}
			if (map[x + 1][y + 1] != 48 + index) {
				map[x + 1][y + 1] = 42;
			}
			else {
				map[x + 1][y + 1] = 48 + index;
			}
			if (map[x + 1][y] != 48 + index) {
				map[x + 1][y] = 42;
			}
			else {
				map[x + 1][y] = 48 + index;
			}
			if (map[x + 1][y - 1] != 48 + index) {
				map[x + 1][y - 1] = 42;
			}
			else {
				map[x + 1][y - 1] = 48 + index;
			}
			if (map[x][y - 1] != 48 + index) {
				map[x][y - 1] = 42;
			}
			else {
				map[x][y - 1] = 48 + index;
			}
		}
		else {
			if (map[x][y + 1] != 48 + index) {
				map[x][y + 1] = 42;
			}
			else {
				map[x][y + 1] = 48 + index;
			}
			if (map[x + 1][y + 1] != 48 + index) {
				map[x + 1][y + 1] = 42;
			}
			else {
				map[x + 1][y + 1] = 48 + index;
			}
			if (map[x + 1][y] != 48 + index) {
				map[x + 1][y] = 42;
			}
			else {
				map[x + 1][y] = 48 + index;
			}
			if (map[x + 1][y - 1] != 48 + index) {
				map[x + 1][y - 1] = 42;
			}
			else {
				map[x + 1][y - 1] = 48 + index;
			}
			if (map[x][y - 1] != 48 + index) {
				map[x][y - 1] = 42;
			}
			else {
				map[x][y - 1] = 48 + index;
			}
			if (map[x - 1][y - 1] != 48 + index) {
				map[x - 1][y - 1] = 42;
			}
			else {
				map[x - 1][y - 1] = 48 + index;
			}
			if (map[x - 1][y] != 48 + index) {
				map[x - 1][y] = 42;
			}
			else {
				map[x - 1][y] = 48 + index;
			}
			if (map[x - 1][y + 1] != 48 + index) {
				map[x - 1][y + 1] = 42;
			}
			else {
				map[x - 1][y + 1] = 48 + index;
			}
		}
	}
}
//отрисовка кораблей
void init_ships(char map[][11], int& x, int& y, int& deck, int& dir, int& index) {
	
	for (int i = 0; i < deck; i++) {					-----
		if (test_init(map, x, y, deck, dir, index)) {
			map[x][y] = 48 + index;
			edging_ship(map, x, y, index);

			if (dir == 1) {
				y++;
			}
			if (dir == 2) {
				x++;
			}
			if (dir == 3) {
				y--;
			}
			if (dir == 4) {
				x--;
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
		enter_coordinates(x, y);
		enter_direction(dir);
		system("cls");
		if (test_location(map, x, y, i)) {
			if (i == 0) {
				deck = 4;
				if (test_init(map, x, y, deck, dir, i)) {
					init_ships(map, x, y, deck, dir, i);
					print_map(map, row, cols);
				}
				else {
					i--;
					print_map(map, row, cols);
					cout << "Can't install ship!" << endl;
				}
			}
			if (i == 1 || i == 2) {
				deck = 3;
				if (test_init(map, x, y, deck, dir, i)) {
					init_ships(map, x, y, deck, dir, i);
					print_map(map, row, cols);
				}
				else {
					i--;
					print_map(map, row, cols);
					cout << "Can't install ship!" << endl;
				}
			}
			if (i == 3 || i == 4 || i == 5) {
				deck = 2;
				if (test_init(map, x, y, deck, dir, i)) {
					init_ships(map, x, y, deck, dir, i);
					print_map(map, row, cols);
				}
				else {
					i--;
					print_map(map, row, cols);
					cout << "Can't install ship!" << endl;
				}
			}
			if (i == 6 || i == 7 || i == 8 || i == 9) {
				deck = 1;
				init_ships(map, x, y, deck, dir, i);
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
//автоматическая расстановка
void avto_location_ships(char map[][11], int row, int cols) {
	int x, y, dir, deck;
	for (int i = 0; i < 10; i++) {
		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		dir = rand() % 4 + 1;
		system("cls");
		if (test_location(map, x, y, i)) {
			if (i == 0) {
				deck = 4;
				if (test_init(map, x, y, deck, dir, i)) {
					init_ships(map, x, y, deck, dir, i);
					print_map(map, row, cols);
				}
				else {
					i--;
					print_map(map, row, cols);
					cout << "Can't install ship!" << endl;
				}
			}
			//if (i == 1 || i == 2) {
			//	deck = 3;
			//	if (test_init(map, x, y, deck, dir, i)) {
			//		init_ships(map, x, y, deck, dir, i);
			//		print_map(map, row, cols);
			//	}
			//	else {
			//		i--;
			//		print_map(map, row, cols);
			//		cout << "Can't install ship!" << endl;
			//	}
			//}
			//if (i == 3 || i == 4 || i == 5) {
			//	deck = 2;
			//	if (test_init(map, x, y, deck, dir, i)) {
			//		init_ships(map, x, y, deck, dir, i);
			//		print_map(map, row, cols);
			//	}
			//	else {
			//		i--;
			//		print_map(map, row, cols);
			//		cout << "Can't install ship!" << endl;
			//	}
			//}
			//if (i == 6 || i == 7 || i == 8 || i == 9) {
			//	deck = 1;
			//	init_ships(map, x, y, deck, dir, i);
			//	print_map(map, row, cols);
			//}
		}
		else {
			cout << "Can't install ship!" << endl;
			i--;
			print_map(map, row, cols);
		}
	}
	system("cls");
}
//выстрел
void shot(char map[][11], int& x, int& y) {
	//int a = 0;
	//int* shot = &a;
	enter_coordinates(x, y);
	system("cls");
	if (test_coordinates(x, y)) {
		int cuont = 0;
		if (map[x][y] == '0') {
			int deck = 4;
			cuont++;
		}
		if (cuont == 4) {
		}


	//	if (map[x][y] == 79) {
	//		if (map[x][y + 1] == 79 ||     //проверка наличия соседних палуб
	//			map[x + 1][y + 1] == 79 ||
	//			map[x + 1][y] == 79 ||
	//			map[x + 1][y - 1] == 79 ||
	//			map[x][y - 1] == 79 ||
	//			map[x - 1][y - 1] == 79 ||
	//			map[x - 1][y] == 79 ||
	//			map[x - 1][y + 1] == 79) {
	//			*shot = 1; //ранен
	//			return shot;
	//		}
	//		else {
	//			*shot = 2; //убил
	//			return shot;
	//			//----------------------------начало обрисовки
	//			if (y == 9) {
	//				map[x][y] = 88;
	//				map[x + 1][y] = 15;
	//				map[x + 1][y - 1] = 15;
	//				map[x][y - 1] = 15;
	//				map[x - 1][y - 1] = 15;
	//				map[x - 1][y] = 15;
	//			}
	//			else if (y == 0) {
	//				map[x][y] = 88;
	//				map[x][y + 1] = 15;
	//				map[x + 1][y + 1] = 15;
	//				map[x + 1][y] = 15;
	//				map[x - 1][y] = 15;
	//				map[x - 1][y + 1] = 15;
	//			}
	//			else {
	//				map[x][y] = 88;
	//				map[x][y + 1] = 15;
	//				map[x + 1][y + 1] = 15;
	//				map[x + 1][y] = 15;
	//				map[x + 1][y - 1] = 15;
	//				map[x][y - 1] = 15;
	//				map[x - 1][y - 1] = 15;
	//				map[x - 1][y] = 15;
	//				map[x - 1][y + 1] = 15;
	//			}
	//			//----------------------------- конец обрисовки
	//		}
	//	}
	//	else {
	//		*shot = 3; //промах
	//		return shot;
	//	}
	//	//map_to_map(my_map, comp_map, row, cols);
	//}
	////else {
	////	shot = 4;
	////	return shot;
	////	//map_to_map(my_map, comp_map, row, cols);
	////	//cout << "You enter incorect valeu !" << endl;
	}

}

int main()
{
	srand(time(NULL));
	const int row = 11,
		cols = 11;
	char my_map[row][cols]{};
	char comp_map[row][cols]{};
	char copy_comp_map[row][cols]{};
	char copy_my_map[row][cols]{};
	init_map(my_map, row, cols);
	init_map(comp_map, row, cols);
	init_map(copy_comp_map, row, cols);
	init_map(copy_my_map, row, cols);

	// игра
	//while (true) {
	//	bool flag = false;
	//	int x, y;
	//	cout << "Enter the coordinates of the shot: " << endl;
	//	cin >> x >> y;
	//	system("cls");
	//	if ((x >= 0 && x <= 10) && (y >= 0 && y <= 10)) {
	//		if (comp_map[x][y] == 79) {
	//			if (comp_map[x][y + 1] == 79 ||     //проверка наличия соседних палуб
	//				comp_map[x + 1][y + 1] == 79 ||
	//				comp_map[x + 1][y] == 79 ||
	//				comp_map[x + 1][y - 1] == 79 ||
	//				comp_map[x][y - 1] == 79 ||
	//				comp_map[x - 1][y - 1] == 79 ||
	//				comp_map[x - 1][y] == 79 ||
	//				comp_map[x - 1][y + 1] == 79) {
	//				comp_map[x][y] = 88;
	//				cout << "Injared !" << endl; //ранен
	//			}
	//			else {
	//				cout << "You hit !" << endl;
	//				if (y == 9) {
	//					comp_map[x][y] = 88;
	//					comp_map[x + 1][y] = 15;
	//					comp_map[x + 1][y - 1] = 15;
	//					comp_map[x][y - 1] = 15;
	//					comp_map[x - 1][y - 1] = 15;
	//					comp_map[x - 1][y] = 15;
	//				}
	//				else if (y == 0) {
	//					comp_map[x][y] = 88;
	//					comp_map[x][y + 1] = 15;
	//					comp_map[x + 1][y + 1] = 15;
	//					comp_map[x + 1][y] = 15;
	//					comp_map[x - 1][y] = 15;
	//					comp_map[x - 1][y + 1] = 15;
	//				}
	//				else {
	//					comp_map[x][y] = 88;
	//					comp_map[x][y + 1] = 15;
	//					comp_map[x + 1][y + 1] = 15;
	//					comp_map[x + 1][y] = 15;
	//					comp_map[x + 1][y - 1] = 15;
	//					comp_map[x][y - 1] = 15;
	//					comp_map[x - 1][y - 1] = 15;
	//					comp_map[x - 1][y] = 15;
	//					comp_map[x - 1][y + 1] = 15;
	//				}
	//			}
	//		}
	//		else {
	//			comp_map[x][y] = 88;
	//			cout << "You missed !" << endl;
	//		}
	//		map_to_map(my_map, comp_map, row, cols);
	//	}
	//	else {
	//		map_to_map(my_map, comp_map, row, cols);
	//		cout << "You enter incorect valeu !" << endl;
	//	}
	//	////остановка игры. закончились корабли
	//	////условие проверки коpаблей на поле
	//	//for (int i = 0; i < row; i++) {
	//	//	for (int j = 0; j < cols; j++) {
	//	//		if (comp_map[i][j] == 79) {
	//	//			flag = true;
	//	//		}if (my_map[i][j] == 79) {
	//	//			flag = true;
	//	//		}
	//	//	}
	//	//}
	//	//if (flag == false) {
	//	//	break;
	//	//}
	//}
	//cout << endl << "You lose..." << endl;
	location_ships(comp_map, row, cols);
	print_map(comp_map, row, cols);

	//мой выстрел
	bool repit_shot = true;
	while (repit_shot) {
		map_to_map(my_map, copy_comp_map, row, cols);
		int x, y;
		int* p_shot = shot(comp_map, x, y);
		if (*p_shot == 1) {
			//map_to_map(my_map, copy_comp_map, row, cols);
			cout << "Injared";
			copy_comp_map[x][y] = 88;
			system("cls");
		}
		if (*p_shot == 2) {
			//map_to_map(my_map, copy_comp_map, row, cols);
			cout << "Hit !";
			copy_comp_map[x][y] = 88;
		}
		if (*p_shot == 3) {
			//map_to_map(my_map, copy_comp_map, row, cols);
			cout << "You missed...";
			repit_shot = true;
			copy_comp_map[x][y] = 88;
		}
	}




	//map_to_map(my_map, comp_map, row, cols);
	//avto_location_ships(comp_map, row, cols);
	//map_to_map(my_map, comp_map, row, cols);


}

//отрисовал карты, выполнил ручную расстановку с проверками на соседство и выход за пределы,
//
// 
// отредактировать название координат

//dir == 1 - право 
//dir == 2 - низ
//dir == 3 - лево
//dir == 4 - верх
//
