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
	"strings"
	"golang.org/x/tour/wc"
)

func WordCount(s string) map[string]int {
	var wds = strings.Fields(s)
	var wdcnt int = len(wds)
	var counts map[string]int = make(map[string]int, wdcnt)

	for i := 0; i < wdcnt; i++ {
			var wd = wds[i]
		
			counts[wd] = 1 + counts[wd]
	}

	return counts
}

func main() {
	wc.Test(WordCount)
}
