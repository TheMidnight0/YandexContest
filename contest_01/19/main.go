package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var i, j, check int
var input, left, result string
var text, text2 []string

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input = scanner.Text()
	text = strings.Split(input, " ")
	for i < len(text) {
		check = 0
		j = i + 1
		for j < len(text) {
			if text[i] == "end" {
				j = len(text) - 1
				i = len(text) - 1
			} else {
				if text[j] == "end" {
					j = len(text) - 1
				} else {
					if text[i] == text[j] && text[i] != "" {
						text[j] = ""
						check = 1
					}
				}
			}
			j++
		}
		if check == 1 {
			text2 = append(text2, text[i])
		}
		i++
	}
	i, j = 0, 0
	for i < len(text2) {
		j = 0
		for j+1 < len(text2) {
			if text2[j] > text2[j+1] {
				text2[j], text2[j+1] = text2[j+1], text2[j]
			}
			j++
		}
		i++
	}
	i = 0
	for i < len(text2) {
		result = result + text2[i] + " "
		i++
	}
	fmt.Println(result)
}
