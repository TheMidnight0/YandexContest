package main
import ("fmt"; "bufio"; "os"; "strings"; "strconv")

var length, i int
var input, result string
var s []string
var temp []float64

func scan() {
    fmt.Scanln(&length)
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    input = scanner.Text()
    s = strings.Split(input, " ")
    for (i != len(s)) {
        char, _ := strconv.ParseFloat(s[i], 64)
        temp = append(temp, char)
        i++
    }
}
func calculate() {
    i = 0
    for (i < len(temp)) {
        if (i == 0 || i+1 == len(temp)) {
            result = result + " " + strconv.FormatFloat(temp[i], 'f', 15, 64)
        } else {
            result = result + " " + strconv.FormatFloat((temp[i-1] + temp[i] + temp[i+1])/3, 'f', 15, 64)
        }
        i++
    }
}

func main() {
    scan()
    calculate()
    fmt.Println(result)
}