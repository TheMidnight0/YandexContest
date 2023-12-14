package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var i, j, max, min, index, length, result int
var input string
var str []string
var island []int

func scan() {
	fmt.Scanln(&length)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input = scanner.Text()
	str = strings.Split(input, " ")
	for i != len(str) {
		char, _ := strconv.Atoi(str[i])
		island = append(island, char)
		i++
	}
}
func calculate() {
	i = 0
	for i < len(island) {
		min = island[i]
		max = 0
		j = i + 1
		for j < len(island) {
			if island[j] < min {
				min = island[j]
			} else {
				if island[j] > max {
					max = island[j]
				}
			}
			j++
		}
		if max > min {
			if max > island[i] {
				max = island[i]
			}
			j = i + 1
			for j < len(island) {
				if island[j] >= max {
					i = j
					j = len(island)
				} else {
					result = result + max - island[j]
				}
				j++
			}
		} else {
			i++
		}
	}
	fmt.Println(result)
}

func main() {
	scan()
	calculate()
}
