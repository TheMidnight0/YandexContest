#include <iostream>
#include <vector>
#include <string>

int x, y;
std::vector<int> path_x, path_y;

int is_can_exit_from_maze(std::vector<std::string> map, int start_y, int start_x) {
    if (map[start_y][start_x] == '#') {
        return 0;
    }
    path_x.push_back(start_x);
    path_y.push_back(start_y);
    while (path_x.size() != 0) {
        x = path_x[0];
        y = path_y[0];
        if (map[y][x] == 'E') {
            return 1;
        }
        if (map[y+1][x] != '#') {
            path_x.push_back(x);
            path_y.push_back(y+1);
        }
        if (map[y-1][x] != '#') {
            path_x.push_back(x);
            path_y.push_back(y-1);
        }
        if (map[y][x+1] != '#') {
            path_x.push_back(x+1);
            path_y.push_back(y);
        }
        if (map[y][x-1] != '#') {
            path_x.push_back(x-1);
            path_y.push_back(y);
        }
        map[y][x] = '#';
        path_x.erase(path_x.begin());
        path_y.erase(path_y.begin());
    }
    return 0;
}

int main(){
    int row, col, rows, cols;
    std::cin >> row >> col >> rows >> cols;
    std::cin.ignore(1); // Игнорируем перевод строки, застрявший в потоке ввода
    std::vector<std::string> maze(rows);
    for(auto& line : maze) std::getline(std::cin, line);
    
    std::cout << (is_can_exit_from_maze(maze, row, col) ? "YES" : "NO") << std::endl;
}