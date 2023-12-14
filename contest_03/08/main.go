package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var count int
	fmt.Scanln(&count)
	var nums map[string]int
	nums = make(map[string]int)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	sep_nums := strings.Split(line, " ")
	for i := 0; count > 0 && i < len(sep_nums); i++ {
		if sep_nums[i] != "" {
			if nums[sep_nums[i]] == 1 {
				nums[sep_nums[i]] = 0
			} else {
				nums[sep_nums[i]] = 1
			}
			count--
		}
	}
	for key, value := range nums {
		if value == 1 {
			fmt.Println(key)
			break
		}
	}
}
