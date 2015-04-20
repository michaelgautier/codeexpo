#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <array>
#include <vector>

using namespace std;

namespace gautier
{
	namespace util
	{
		using n_type = decltype(std::string::npos);

		const auto NOPOSITION = -1;
		const auto prefix_record = 0;
		const auto prefix_num = 1;
		const auto prefix_field = 2;

		auto get_n(const std::string& line_data, const n_type& start_pos) -> decltype(NOPOSITION)
		{
			auto return_value = NOPOSITION;
			auto pos = start_pos;

			if(pos != std::string::npos)
			{
				std::string data = "";

				for(; pos < line_data.size(); pos++)
				{
					auto datum = line_data[pos];

					if(std::isdigit(datum))
					{
						data += datum;
					}

					else
					{
						/*digits must be consecutive.*/
						break;
					}
				}

				if(!data.empty())
				{
					return_value = std::stoi(data);
				}
			}

			return return_value;
		}

		auto execute(const std::string& file_name)-> void
		{
			const std::string braid(60, '-');

			const std::string line_headings[] =
			{
				"/file/record",
				"/file/record/@num",
				"/file/record/field"
			};

			const std::string op_delim = "=";

			std::array<std::string, 48> column_names;

			auto max_fln_dyn = 0;

			ifstream file_input;
			file_input.open(file_name);

			if(file_input)
			{
				auto rln = 0;
				auto fln = 0;
				auto idx = 0;
				std::string line_data = "";
				std::string data = "";

				while(file_input.good() && !file_input.eof())
				{
					getline(file_input, line_data);
					/*record at beginning?*/
					rln = (line_data == line_headings[prefix_record])
					      ? NOPOSITION
					      : rln;
					auto new_record = (rln == NOPOSITION);
					/*record's line # available?*/
					rln = (rln == NOPOSITION)
					      && line_data.find(line_headings[prefix_num]) == 0
					      ? get_n(line_data, line_data.find(op_delim) + 1)
					      : rln;
					/*record's field # accessible?*/
					fln = (rln != NOPOSITION)
					      && line_data.find(line_headings[prefix_field]) == 0
					      ? get_n(line_data, line_headings[prefix_field].size())
					      : fln;
					/*record's field data accessible?*/
					idx = (fln != NOPOSITION)
					      ? line_data.find(op_delim)
					      : NOPOSITION;
					/*acquire data if available.*/
					data = (idx != NOPOSITION)
					       ? line_data.substr(idx + 1)
					       : "";

					if(rln == 0)
					{
						column_names[fln] = data;
						max_fln_dyn = fln;
					}

					else if(new_record)
					{
						if(rln != NOPOSITION)
						{
							std::cout << braid << "\n";
							std::cout << "record # " << rln << "\n";
							std::cout << braid << "\n";
						}
					}

					else
					{
						std::cout << "|" << std::setw(2) << fln << "| " << std::setw(18) << std::left << column_names[fln] << ": " << data << "\n";

						if(fln == max_fln_dyn)
						{
							std::cout << "\n";
						}
					}
				}
			}

			return;
		}

	}
}

auto main(int argc, char* argv[]) -> int
{
	std::string file_path = "";

	for(auto char_index = 0; char_index < argc; char_index++)
	{
		if(char_index == 1)
		{
			file_path = argv[char_index];
			break;
		}
	}

	if(!file_path.empty())
	{
		gautier::util::execute(file_path);
	}

	return 0;
}
