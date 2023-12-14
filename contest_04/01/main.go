package main

import (
	"encoding/json"
	"fmt"
	"os"
)

type Project struct {
	Tasks []User `json:"tasks"`
}

type User struct {
	UserId    int  `json:"user_id"`
	Completed bool `json:"completed"`
}

func main() {
	var inf, result int
	result = 0
	fmt.Scanln(&inf)
	data, _ := os.ReadFile("data.json")
	var unmar []Project
	json.Unmarshal(data, &unmar)
	for i := range unmar {
		for j := range unmar[i].Tasks {
			if unmar[i].Tasks[j].UserId == inf && unmar[i].Tasks[j].Completed {
				result++
			}
		}
	}
	fmt.Println(result)
}
