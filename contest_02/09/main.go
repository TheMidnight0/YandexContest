package main
import (
    "bufio"
    "fmt"
    "os"
)

import "strconv"

func isLucky(line string) bool {
    var i, j, num1, num2 int
    i = 0
    j = len(line)-3
    for (i <= 2) {
        temp, _ := strconv.Atoi(string(line[i]))
        num1 = num1 + temp
        i++
    }
    for (j < len(line)) {
        temp, _ := strconv.Atoi(string(line[j]))
        num2 = num2 + temp
        j++
    }
    return num1 == num2
}

func main() {
    number, _  := bufio.NewReader(os.Stdin).ReadString('\n')
    if isLucky( number[:len(number)-1] ){  // Обрезаем \n в конце строки
        fmt.Println("YES")
    }else{
        fmt.Println("NO")
    }
}