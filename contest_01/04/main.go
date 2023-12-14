package main
import ("fmt"; "math")
var a float64
var b float64
func main() {
    fmt.Scanln(&a, &b)
    if (math.Abs(a) > 10000 || math.Abs(b) > 10000) {
        fmt.Print("No more than 10000!")
    } else {
        fmt.Println(a * b)
    }
}