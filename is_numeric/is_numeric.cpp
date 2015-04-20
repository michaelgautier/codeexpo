/*Copyright 2015 Michael Gautier, Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at	http://www.apache.org/licenses/LICENSE-2.0

Software distributed under the License is distributed on an "AS IS" BASIS,
NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
See the License for details on permissions and limitations.*/

#include <iostream>
#include <algorithm>

/*Simple Is-Numeric function in C++*/
bool is_digit(const char value) { return std::isdigit(value); }
bool is_numeric(const std::string& value) { return std::all_of(value.begin(), value.end(), is_digit); }

int main()
{
	std::string str1 = "salfkja;sdk";
	std::string str2 = "kljw3298slk3";
	std::string str3 = "238947238";

	std::cout << "str1 " << str1 << " is numeric " << is_numeric(str1) << "\n";
	std::cout << "str2 " << str2 << " is numeric " << is_numeric(str2) << "\n";
	std::cout << "str3 " << str3 << " is numeric " << is_numeric(str3) << "\n";
}
