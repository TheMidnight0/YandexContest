package main
import "fmt"

const rows int = 9
const cols int = 9

func isValidSudoku(map0 [9][9]int) bool {
    var i, j, m, x, y, count int
    for (i < 9) {
        j = 0
        for (j < 9) {
            x = j/3
            y = i/3
            m = 0
            count = 0
            for (m < 9) {
                if (map0[i][j] == map0[y*3+m/3][x*3+m%3]) {
                    count++
                }
                m++
            }
            x = j
            y = i
            for (x < 9) {
                if (map0[i][j] == map0[y][x]) {
                    count++
                }
                x++
            }
            x = j
            for (y < 9) {
                if (map0[i][j] == map0[y][x]) {
                    count++
                }
                y++
            }
            if (count > 3) {
                return false
            }
            j++
        }
        i++
    }
    return true
}

func main() {
    var bord [rows][cols]int
    
    for row:=0; row < rows; row++ {
        for col:=0; col < cols; col++ {
            fmt.Scanf("%c", &bord[row][col])  // Считываем один символ
            bord[row][col] -= '0'  // Чтобы из ASCII кода символа получить цифру
        }
        fmt.Scanf("\n")
    }
    
    if isValidSudoku(bord){
        fmt.Println("YES")
    }else{
        fmt.Println("NO")
    }
}