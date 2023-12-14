package main
import ("fmt")

var N, n int
var result string

func main() {
    fmt.Scanln(&N)
    for (N > 0) {
        n = (N-1)%26
        N = (N-1)/26
        result = string(n + 'A') + result
    }
    fmt.Println(result)
}