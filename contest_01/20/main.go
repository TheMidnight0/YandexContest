package main
import ("fmt"; "strings")

var i, j, found int
var a, b, seek, result string
var array_a, array_b []string

func main() {
    fmt.Scanln(&a, &b)
    array_a = strings.Split(a, "")
    array_b = strings.Split(b, "")
    for i < len(array_a) {
        j = 0
        found = 0
        seek = array_a[i]
        for j < len(array_b) {
            if seek == array_b[j] {
                array_b[j] = ""
                found = 1
                j = len(array_b)-1
            }
            j++
        }
        if found != 1 {
            result = "NO"
            i = len(array_a)-1
        }
        i++
    }
    if result != "NO" {
        result = "YES"
    }
    fmt.Println(result)
}