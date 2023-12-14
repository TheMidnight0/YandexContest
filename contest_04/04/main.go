package main
import (
    "fmt"
    "encoding/csv"
    "os"
    "strings"
    "strconv"
    "sort"
)

type tuple struct {
    name string
    age uint64
}

var result []tuple

func main() {
	var pclass string
	var age uint64
    file, _ := os.ReadFile("train.csv")
    ff := strings.NewReader(strings.ReplaceAll(string(file), "\r", "\n"))
    text, _ := csv.NewReader(ff).ReadAll()
    fmt.Scanln(&pclass, &age)
    for _, line := range text {
        i, _ := strconv.ParseUint(line[5],10,64)
        if line[2] == pclass && line[4] == "female" && i > age {
            result = append(result, tuple{line[3], i})
        }
    }
    sort.Slice(result, func(i, j int) bool {
        if result[i].age == result[j].age {
            return result[i].name < result[j].name
        }
        return result[i].age < result[j].age
    })
    for _, line := range result {
        fmt.Println(line.name)
    }
}
