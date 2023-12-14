package main
import "fmt"

var a, b, c int

func main() {
    fmt.Scanln(&a,&b,&c)
    if (a>b) {
        if (a>c) {
            fmt.Println(a)
        } else {
            fmt.Println(c)
        }
    } else {
        if (b>c) {
            fmt.Println(b)
        } else {
            fmt.Println(c)
        }
    }
}