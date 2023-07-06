#include <iostream>
#include <limits>
#include <numeric>


bool isValidInput(int value) {
    if (std::cin.fail() || std::cin.peek() != '\n' || value < 0 || value > 10) {
        std::wcerr << L"Ошибка ввода данных.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool isValidPosition(int array[], bool field[][10]) {
    if (field[array[0]][array[1]]) {
        return false;
    } 
    return true;
}

bool isValidShip(int size, int start_p[2], int end_p[2], bool field[][10]) {
    int position[2];
    if (start_p[0] != end_p[0] && start_p[1] != end_p[1]) {
        std::wcout << L"Корабль должен распологаться только вертикально или только горизонтально!\n";
        return false;
    } else {
        if (start_p[0] == end_p[0]) {
            for (int i = std::min(start_p[1], end_p[1]); i <= std::max(start_p[1], end_p[1]); i++) {
                position[0] = start_p[0];
                position[1] = i;
                if (!isValidPosition(position, field)) {
                    std::wcout << L"Не подошли координаты!\n";
                    return false;
                }
            }
            if (std::abs(start_p[1] - end_p[1]) != size - 1) {
                std::cout << start_p[1] << " " << end_p[1] << "\n";
                std::wcout << L"Неверна длина\n";
                return false;
                
            } 
        } else if (start_p[1] == end_p[1]) {
            for (int i = std::min(start_p[0], end_p[0]) - 1; i < std::max(start_p[0], end_p[0]); i++) {
                position[0] = i;
                position[1] = start_p[1];
                if (!isValidPosition(position, field)) {
                    return false;
                }
            }
            if (std::abs(start_p[0] - end_p[0]) != size - 1) {
                return false;
            }
        }
    }
    return true;
}

int* coordinats(bool array[][10], int position[2]) {
    int coord_x, coord_y;
    std::wcout << L"Строка: ";
    std::cin >> coord_x;
    while (!isValidInput(coord_x)) {
        std::wcout << L"Строка: ";
        std::cin >> coord_x;
    }

    std::wcout << L"Столбец: ";
    std::cin >> coord_y;
    while (!isValidInput(coord_y)) {
        std::wcout << L"Столбец: ";
        std::cin >> coord_y;
    }
    position[0] = coord_x - 1;
    position[1] = coord_y - 1;

    if (isValidPosition(position, array)) {
        return position;
    } else {
        std::wcout << L"\nОшибка расположения. Введите координаты заново.\n";
        return coordinats(array, position);
    }
}

int* positionTheShip(bool array[][10], int valid_coordinats[][2], int size) {
    int start_position[2], end_position[2];
    if (size != 1) {
        std::wcout << L"\nКоординаты начала.\n";
        coordinats(array, start_position);

        std::wcout << L"\nКоординаты конца.\n";
        coordinats(array, end_position);
        valid_coordinats[0][0] = start_position[0];
        valid_coordinats[0][1] = start_position[1];
        valid_coordinats[1][0] = end_position[0];
        valid_coordinats[1][1] = end_position[1];
        return *valid_coordinats;
    } else {
        std::wcout << L"\nКоординаты корабля.\n";
        coordinats(array, start_position);
        valid_coordinats[0][0] = start_position[0];
        valid_coordinats[0][1] = start_position[1];
        return *valid_coordinats;
    }
    
}

bool addShipOnField(int valid_coordinats[2][2], bool field[][10], int size) {
    if (size > 2) {
        if (valid_coordinats[0][0] == valid_coordinats[1][0]) {
            for (int i = std::min(valid_coordinats[0][1], valid_coordinats[1][1]); i <= std::max(valid_coordinats[0][1], valid_coordinats[1][1]); i++)
            {
                field[valid_coordinats[0][0]][i] = true;
            }
        } else if (valid_coordinats[0][1] == valid_coordinats[1][1]) {
            for (int i = std::min(valid_coordinats[0][0], valid_coordinats[1][0]); i <= std::max(valid_coordinats[0][0], valid_coordinats[1][0]); i++)
            {
                field[i][valid_coordinats[0][1]] = true;
            }
        }
        return field;
    } else if (size == 2){
        field[valid_coordinats[0][0]][valid_coordinats[0][1]] = true;
        field[valid_coordinats[1][0]][valid_coordinats[1][1]] = true;
        return field;
    } else {
        field[valid_coordinats[0][0]][valid_coordinats[0][1]] = true;
        return field;
    }

}

void printField(bool array[][10]) 
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (array[i][j]) {
                std::cout << "|_|" << "\t"; 
            } else {
               std::cout << " _ " << "\t"; 
            }
            
        }
        std::cout << "\n";
    }
}

bool startField(bool array[][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            array[i][j] = false;
        }
    }
    return array;
}

bool fillFieldOfShips(bool array[][10]) {
    int add_coordinats[2][2];

    std::wcout << L"Введите координаты начала и конца 4-х палубного корабля.\n";
    positionTheShip(array, add_coordinats, 4);
    while (!isValidShip(4, add_coordinats[0], add_coordinats[1], array)) {
        std::wcout << L"Ошибка расположения, введите координаты ещё раз.\n";
        positionTheShip(array, add_coordinats, 4);
    }
    addShipOnField(add_coordinats, array, 4);
    printField(array);

    for (int _ = 0; _ < 2; _++) {
        std::wcout << L"Введите координаты начала и конца 3-х палубного корабля.\n";
        positionTheShip(array, add_coordinats, 3);
        while (!isValidShip(3, add_coordinats[0], add_coordinats[1], array)) {
            std::wcout << L"Ошибка расположения, введите координаты ещё раз.\n";
            positionTheShip(array, add_coordinats, 3);
        }
        addShipOnField(add_coordinats, array, 3);
        printField(array);
    }

    

    for (int _ = 0; _ < 3; _++) {
        std::wcout << L"Введите координаты начала и конца 2-х палубного корабля.\n";
        positionTheShip(array,add_coordinats, 2);
         while (!isValidShip(2, add_coordinats[0], add_coordinats[1], array)) {
            std::wcout << L"Ошибка расположения, введите координаты ещё раз.\n";
            positionTheShip(array, add_coordinats, 2);
        }
        addShipOnField(add_coordinats, array, 2);
        printField(array);
    }

    

    for (int _ = 0; _ < 4; _++) {
        std::wcout << L"Введите координаты начала и конца однопалубного корабля.\n";
        positionTheShip(array,add_coordinats, 1);
        while(!isValidPosition(add_coordinats[0], array)) {
            std::wcout << L"Ошибка расположения, введите координаты ещё раз.\n";
            positionTheShip(array,add_coordinats, 1);
        }
        addShipOnField(add_coordinats, array, 1);
        printField(array);
    }
    return array;
}

std::string isWinner(std::string field_1[][10], std::string field_2[][10]) {
    int hit_count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (field_1[i][j] == "|X|") {
                hit_count++;
            }
        }
    }
    if (hit_count == 20) {
        return "first";
    }
    hit_count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (field_2[i][j] == "|X|") {
                hit_count++;
            }
        }
    }
    if (hit_count == 20) {
        return "first";
    }
    return "Nobody";
}

std::string* gameField(bool field[][10], std::string new_field[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (field[i][j]) {
                new_field[i][j] = "|_|";
            } else {
                new_field[i][j] = " _ ";
            }
        }
    }
    return *new_field;
}

std::string* fillHitField(std::string hit_field[][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            hit_field[i][j] = " _ ";
        }
    }
    return *hit_field;
}

void printGameField (std::string field[][10], std::string hit_field[][10]) {
    for (int i = 0; i < 10; i++) {
        std::cout << "||" << "\t";
        for (int j = 0; j < 10; j++) {
            std::cout << field[i][j] << "\t";
        }
        std::cout << "||" << "\t" << "||" << "\t";
        for (int j = 0; j < 10; j++) {
            std::cout << hit_field[i][j] << "\t";
        }
        std::cout << "||\n";
    }
}

char shoot(std::string field[][10], std::string hit_field[][10]) {
    int coord_x, coord_y;
    std::wcout << L"Введите точку стрельбы:\n";
    std::wcout << L"Строка: ";
    std::cin >> coord_x;
    while (!isValidInput(coord_x)) {
        std::wcout << L"Строка: ";
        std::cin >> coord_x;
    }

    std::wcout << L"Столбец: ";
    std::cin >> coord_y;
    while (!isValidInput(coord_y)) {
        std::wcout << L"Столбец: ";
        std::cin >> coord_y;
    }

    if (field[coord_x-1][coord_y-1] == "|_|") {
        field[coord_x-1][coord_y-1] = "|X|";
        hit_field[coord_x-1][coord_y-1] = " X ";
        return 'X';
    } else {
        hit_field[coord_x-1][coord_y-1] = " O ";
        return 'O';
    }
}

int main() {
    setlocale(LC_ALL, "");

    
    bool firstPlayerField[10][10], secondPlayerField[10][10];
    startField(firstPlayerField);
    startField(secondPlayerField);
    std::string game_field_first_player[10][10];
    std::string game_field_second_player[10][10];
    std::string hit_field_first_player[10][10];
    std::string hit_field_second_player[10][10];


    std::wcout << L"Добро пожаловать в игру орской бой!!!\nПравила игры:\nИгроки по очереди заполняют свои игровые поля. Расположение кораблей должно быть строго вертикальным или горихонтадьным;\n";
    std::wcout << L"У игроков есть два поля, на одном указаны их корабли, на втором промахи и попадания:\n|_| - корабль на игровом поле;\n|X| - Подбитый корабль на игровом поле\n";
    std::wcout << L" X  - попадание на вспомогательном поле;\n O  - промах на вспомогательном поле.\n";
    std::wcout << L"Каждый игрок стреляет, пока не промахнётся. После промаха наступает ход второго игрока.\n";

    std::wcout << L"Поле заполняет первый игрок.\n";
    fillFieldOfShips(firstPlayerField);
    gameField(firstPlayerField, game_field_first_player);
    fillHitField(hit_field_first_player);

    std::wcout << L"Поле заполняет второй игрок.\n";
    fillFieldOfShips(secondPlayerField);
    gameField(secondPlayerField, game_field_second_player);
    fillHitField(hit_field_second_player);

    while (true) {
        bool winner = false;
        bool isHitted = true;
        char shoot_result;
        while (isHitted) {
            std::wcout << L"Стреляет первый игрок.\n";
            printGameField(game_field_first_player, hit_field_first_player);
            shoot_result = shoot(game_field_second_player, hit_field_first_player);
            if (shoot_result == 'O') {
                std::wcout << L"Промах!\n";
                isHitted = false;
            } else {
                std::wcout << L"Попадание! \n";
                if (isWinner(game_field_first_player, game_field_second_player) == "first") {
                    std::wcout << L"Победил первый игрок!\n";
                    winner = true;
                    break;
                } 
                    std::wcout << L"Попадание! \n";
                
            }
        }
        if (winner) {
            break;
        }

        isHitted = true;
        while (isHitted) {
            std::wcout << L"Стреляет второй игрок.\n";
            printGameField(game_field_second_player, hit_field_second_player);
            shoot_result = shoot(game_field_first_player, hit_field_second_player);
            if (shoot_result == 'O') {
                std::wcout << L"Промах!\n";
                isHitted = false;
            } else {
                std::wcout << L"Попадание!\n";
                if (isWinner(game_field_second_player, game_field_first_player) == "second") {
                    std::wcout << L"Победил второй игрок!\n";
                    winner = true;
                    break;
                }
            }
        }
        if (winner) {
            break;
        }
    }
    
    
}