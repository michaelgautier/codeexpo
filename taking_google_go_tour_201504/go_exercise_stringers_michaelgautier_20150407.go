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
	"fmt"
	"strconv"
	"strings"
)

type IPAddr [4]byte

func (ip IPAddr) String() string {
	var vals [len(ip)]string

	for i := 0; i < len(ip); i++ {
		var num int64 = int64(ip[i])

		vals[i] = strconv.FormatInt(num, 10)
	}

	return strings.Join(vals[0:], ".")
}

func main() {
	addrs := map[string]IPAddr{
		"loopback":  {127, 0, 0, 1},
		"googleDNS": {8, 8, 8, 8},
	}
	for n, a := range addrs {
		fmt.Printf("%v: %v\n", n, a)
	}
}

