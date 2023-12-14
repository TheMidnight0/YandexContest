package main
import "fmt"

func shift(data []int, steps int) {
    var temp [10]int
    var i, np int
    for (i < len(temp)) {
        if ((i+steps) < 0) {
            np = i+steps - ((i+steps-9)/10)*10
        } else {
            np = i+steps - ((i+steps)/10)*10
        }
        temp[np] = data[i]
        i++
    }
    i = 0
    for (i < len(temp)) {
        data[i] = temp[i]
        i++
    }
}

func main(){
    var steps int
    fmt.Scan(&steps)

    var data [10]int
    for index := range data{
        fmt.Scan(&data[index])
    }

    shift(data[:], steps);
    for _, value := range data{
        fmt.Printf("%d ", value)
    }
}