/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/

/*
	Taking the Google Go Tour with Exercise Solutions
	https://gautiertalkstechnology.wordpress.com/2015/04/08/taking-the-google-go-tour-with-exercise-solutions/
*/

package main

import (
	"golang.org/x/tour/pic"
)

func Pic(dx, dy int) [][]uint8 {
	var sl = make([][]uint8, dy)

	for i:=0; i < dy; i++ {
		sl[i] = make([]uint8, dx)
		for di:=0; di < dx; di++ {
			val := &sl[i][di]
			*val = uint8( ( (dx * i) + (dy+di) ) / 2 )
		}
	}
	
	return sl
}

func main() {
	pic.Show(Pic)
}
