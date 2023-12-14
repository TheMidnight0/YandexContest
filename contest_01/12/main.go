package main
import "fmt"
var X, i int

func main() {
    fmt.Scanln(&X)
    if (X < 1) {
        fmt.Println("X required to be a positive number!")
    } else {
        for (X > 1) {
            if (X%2==0) {
                X=X/2
                i++
            } else {
                X=3*X+1
                i++
            }
        }
        fmt.Println(i)
    }
}