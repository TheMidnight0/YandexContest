package main

import "fmt"

func fill(map0 [][]int) {
    var x, y, m, count, rows, cols int
    rows = len(map0)
    cols = len(map0[0])
    for (y < rows) {
        x = 0
        for (x < cols) {
            if (map0[y][x] != -1) {
                m = 0
                count = 0
                for (m < 9) {
                    if (x+(m%3)-1 <= cols-1 && x+(m%3)-1 >= 0 && y+(m/3)-1 <= rows-1 && y+(m/3)-1 >= 0) {
                        if (map0[y+(m/3)-1][x+(m%3)-1] == -1) {
                            count++
                        }
                        
                    }
                    m++
                }
                map0[y][x] = count
            }
            x++
        }
        y++
    }
}

func main() {
    var rows, cols int
    fmt.Scanf("%d %d\n", &rows, &cols)
    
    // Создаём срез и заполняем его данными о расположении мин
    maze := make([][]int, rows, rows)
    for i := range maze {
        maze[i] = make([]int, cols, cols)
        for j := range maze[i] {
            fmt.Scanf("%d", &maze[i][j])
        }
    }
    
    // Заполняем игровое поле подсказками
    fill(maze)
    
    // Выводим на экран
    for _, row := range maze {
         for _, cell := range row {
             fmt.Printf("%3d", cell)
        }
        fmt.Println()
    }
}