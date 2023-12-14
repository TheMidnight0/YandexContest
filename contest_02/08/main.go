package main
import (
    "bufio"
    "fmt"
    "os"
)

import ("strings"; "regexp")

func isPalindrome(line string) bool {
    var swap string
    var i int
    var re = regexp.MustCompile(`[[:punct:]]|[[:space:]]`)
    line = strings.ToLower(re.ReplaceAllString(line, ""))
    i = len(line)-1
    for (i >= 0) {
        swap = swap + string(line[i])
        i--
    }
    return swap == line
}

func main() {
    line, _  := bufio.NewReader(os.Stdin).ReadString('\n')
    if isPalindrome( line[:len(line)-1] ){  // Обрезаем \n в конце строки
        fmt.Println("YES")
    }else{
        fmt.Println("NO")
    }
}