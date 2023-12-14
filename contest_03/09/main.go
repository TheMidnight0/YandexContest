package main

import "fmt"

func main() {
	col, x, num1, num2, key := 0, 0, 0, 0, 0
	nums := make(map[int]int)
	fmt.Scanln(&col, &x)
	for i := 0; i < col; i++ {
		fmt.Scan(&key)
		if nums[key] == 1 {
			if key <= x-key {
				num1 = key
				num2 = x - key
			} else {
				num1 = x - key
				num2 = key
			}
		} else {
			nums[x-key] = 1
		}
	}
	fmt.Println(num1, num2)
}
