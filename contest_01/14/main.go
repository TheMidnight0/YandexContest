package main

import (
	"fmt"
	"strconv"
)

var row, col, m, n int
var str, str2 string

func check() {
	if row < 1 || row > 31 || col < 1 || col > 31 {
		fmt.Println("Row and column cannot be more than 31 or less than 1!")
	} else {
		f_s_row()
		rows()
	}
}
func f_s_row() {
	str = "    |"
	str2 = "   --"
	for m != col {
		m++
		if m < 10 {
			str = str + "   " + strconv.Itoa(m)
		} else {
			str = str + "  " + strconv.Itoa(m)
		}
		str2 = str2 + "----"
	}
	fmt.Println(str)
	fmt.Println(str2)
}
func rows() {
	m = 0
	for m != row {
		n = 0
		m++
		if m < 10 {
			str = "   " + strconv.Itoa(m) + "|"
		} else {
			str = "  " + strconv.Itoa(m) + "|"
		}
		for n != col {
			n++
			if m*n > 99 {
				str = str + " " + strconv.Itoa(m*n)
			} else {
				if m*n > 9 {
					str = str + "  " + strconv.Itoa(m*n)
				} else {
					str = str + "   " + strconv.Itoa(m*n)
				}
			}

		}
		fmt.Println(str)
	}
}

func main() {
	fmt.Scanln(&row, &col)
	check()
}
