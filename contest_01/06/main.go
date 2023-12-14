package main
import "fmt"

var sum, a, b, c, d, e int

func result() {
    for sum>=5000 {
        sum=sum-5000
        a=a+1
    }
    for sum>=1000 {
        sum=sum-1000
        b=b+1
    }
    for sum>=500 {
        sum=sum-500
        c=c+1
    }
    for sum>=200 {
        sum=sum-200
        d=d+1
    }
    e = sum/100
}

func main() {
    fmt.Scanln(&sum)
    if (sum%100 != 0) {
        fmt.Println("Number is required to be multiplied to 100!")
    } else {
        result()
        fmt.Println(a, b, c, d, e)
    }
}