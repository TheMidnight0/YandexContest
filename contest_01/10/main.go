package main
import "fmt"
var a, b, c string

func main() {
    fmt.Scanln(&a,&b,&c)
    if (a=="Нет"&&b=="Нет"&&c=="Нет") {
        fmt.Println("Кот")
    }
    if (a=="Нет"&&b=="Нет"&&c=="Да") {
        fmt.Println("Жираф")
    }
    if (a=="Нет"&&b=="Да"&&c=="Нет") {
        fmt.Println("Курица")
    }
    if (a=="Нет"&&b=="Да"&&c=="Да") {
        fmt.Println("Страус")
    }
    if (a=="Да"&&b=="Нет"&&c=="Нет") {
        fmt.Println("Дельфин")
    }
    if (a=="Да"&&b=="Нет"&&c=="Да") {
        fmt.Println("Плезиозавры")
    }
    if (a=="Да"&&b=="Да"&&c=="Нет") {
        fmt.Println("Пингвин")
    }
    if (a=="Да"&&b=="Да"&&c=="Да") {
        fmt.Println("Утка")
    }
    if (a!="Да"&&a!="Нет"||b!="Да"&&b!="Нет"||c!="Да"&&c!="Нет") {
        fmt.Println("Answers must be 'Да' or 'Нет'!")
    }
}