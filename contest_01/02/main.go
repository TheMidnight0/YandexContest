package main

import (
	"fmt"
	"math"
)

var dubzagod = 20.0
var topolzagod = 32.0
var chelzaden = 0.5

func main() {
	var tratzagod = chelzaden * 365
	var topol = math.Ceil(tratzagod / topolzagod)
	var dub = math.Ceil(tratzagod / dubzagod)
	fmt.Println(tratzagod, topol, dub)
}
