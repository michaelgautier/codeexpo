/*
	Copyright 2015 Michael Gautier

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

/*Includes: Standard Library*/
#include <algorithm>
#include <vector>
#include <chrono>
#include <iostream>
#include <sstream>
#include <memory>
#include <utility>
#include <iterator>
#include "json/json.h"

/*Includes: SFML*/
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#define UXOFF

namespace gautier
{
	/*
		Enums
	*/
	enum interaction_def_type
	{
		interaction_def_type_none = 0,
		interaction_def_type_composition,
		interaction_def_type_planar_def
	};
	
	/*
		Aliases
	*/
	using type_principle_map_key = std::pair<interaction_def_type, std::string>;
	using type_text_keyvalues_map = std::map<std::string, std::string>;
	using type_principle_key_map = std::map<std::string, interaction_def_type>;

	static constexpr auto OUTENDL = "\n";

	static auto get_jsoncpp_value_type_name(const int type_code) -> std::string
	{
		std::string type_name;
	
		switch(type_code)
		{
			case Json::ValueType::nullValue://'null' value
				type_name = "null";
			break;
			case Json::ValueType::intValue://signed integer value
				type_name = "int";
			break;
			case Json::ValueType::uintValue://unsigned integer value
				type_name = "uint";
			break;
			case Json::ValueType::realValue://double value
				type_name = "real";
			break;
			case Json::ValueType::stringValue://UTF­8 string value.
				type_name = "string";
			break;
			case Json::ValueType::booleanValue://bool value
				type_name = "boolean";
			break;
			case Json::ValueType::arrayValue://array value (ordered list)
				type_name = "array";
			break;
			case Json::ValueType::objectValue://object value (collection of name/value pairs).
				type_name = "object";
			break;
		}

		return type_name;
	}

	static auto get_json_node_is_value_type(const Json::Value& instance_node) -> bool
	{
		return (instance_node.isIntegral() || instance_node.isString());
	}

	static auto make_default_interactive_def_primary_key() -> type_principle_map_key
	{
		return std::make_pair(interaction_def_type::interaction_def_type_none, "");
	}

	static auto get_interactive_def_primary_key(const std::string& value, const type_principle_key_map& instance_principle_key_map) -> type_principle_map_key
	{
		type_principle_map_key instance_primary_key = make_default_interactive_def_primary_key();

		auto candidate_key = instance_principle_key_map.find(value);
		
		if(candidate_key != instance_principle_key_map.end())
		{
			instance_primary_key = std::make_pair(candidate_key->second, candidate_key->first);
		}

		return instance_primary_key;
	}
}

namespace gautier
{
	namespace interaction
	{
		/*
			Types
		*/
		struct planar_def
		{
			std::string name;
			std::string text;
			float x,
			      y,
			      width,
			      height;
		};

		struct composition
		{
			std::string name;
			std::string text;
			std::map<std::string, planar_def> composites;
		};

		/*
			Aliases
		*/
		using type_interaction_model = std::map<std::string, composition>;
		using type_interaction_context = std::unique_ptr<sf::RenderWindow>;

		/*
			Instances
		*/
		#ifndef UXOFF
		static type_interaction_context instance_interaction_context;
		#endif

		/*
			Methods
		*/
		auto axis_modify_x_right_align(const planar_def& in_bnds, planar_def& out_bnds) -> int
		{
			out_bnds.x = (in_bnds.width - out_bnds.width) + in_bnds.x;

			return out_bnds.x;
		}

		auto axis_modify_x_center_align(const planar_def& in_bnds, planar_def& out_bnds) -> int
		{
			out_bnds.x = ((in_bnds.width / 2) + in_bnds.x) - (out_bnds.width / 2);

			return out_bnds.x;
		}

		auto axis_modify_y_space_align(const int& magnitude, const planar_def& in_bnds, planar_def& out_bnds) -> int
		{
			out_bnds.y = (in_bnds.y - in_bnds.height) - magnitude;

			return out_bnds.y;
		}

		auto axis_modify_y_center_align(const planar_def& in_bnds, planar_def& out_bnds) -> int
		{
			out_bnds.y = (in_bnds.y) - ((in_bnds.height / 2) - (out_bnds.height / 2));

			return out_bnds.y;
		}

		auto axis_modify_y_top_align(const planar_def& in_bnds, planar_def& out_bnds) -> int
		{
			out_bnds.y = (in_bnds.y + in_bnds.height) - out_bnds.height;

			return out_bnds.y;
		}

		auto Function01_InputMappedToGeometry() -> int
		{
			return 0;
		}

		auto Function02_VisualStructureToVisualOutput() -> int
		{
			return 0;
		}

		auto configure_interaction_context(const std::pair<float, float>& default_extent, const std::string& default_title) -> void
		{
			#ifndef UXOFF
			/*
				Overall visual window
					Everything visual/interactive will fit inside this container by default.
			*/
			instance_interaction_context.reset(
			    new sf::RenderWindow(
			        sf::VideoMode(
			            default_extent.first,
			            default_extent.second
			        ),
			        default_title
			    )
			);
			#endif

			return;
		}

		auto execute_interaction() -> int
		{
			#ifndef UXOFF
			// Start the loop
			while(instance_interaction_context->isOpen())
			{
				// Process events
				sf::Event event;

				while(instance_interaction_context->pollEvent(event))
				{
					// Close window : exit
					if(event.type == sf::Event::Closed)
					{
						instance_interaction_context->close();
					}
				}

				// Clear screen
				instance_interaction_context->clear(sf::Color::Blue);
				// Update the window
				instance_interaction_context->display();
			}
			#endif
			
			return 0;
		}
	}
}

namespace gautier
{
	namespace program
	{
		using namespace gautier::interaction;

		/*
			Constants
		*/
		//static constexpr short DEFAULT_MAX_UNITS = 80;
		static constexpr short ICTX_DEFAULT_WIDTH = 1024;
		static constexpr short ICTX_DEFAULT_HEIGHT = 728;

		static constexpr std::pair<float, float> ICTX_DEFAULT_EXTENT =
		{
			ICTX_DEFAULT_WIDTH,
			ICTX_DEFAULT_HEIGHT
		};

		static const std::string COUT_SECTION = "----------------------------";
		static const std::string ICTX_DEFAULT_TITLE = "Gautier App Context";

		/*
			Aliases
		*/

		/*
			Instances
		*/
		static type_interaction_model instance_interaction_models;
		static type_principle_key_map instance_interaction_def_primary_keys;

		static type_text_keyvalues_map instance_text_keyvalues;
		static type_principle_map_key instance_principle_map_key;

		/*
			Functions
		*/

		auto output_model_to_console() -> void
		{
			//std::cout << "model size " << instance_interaction_models.size() << OUTENDL;

			for(auto entry_composition : instance_interaction_models)
			{
				std::cout << "entry name, composition " << entry_composition.first << OUTENDL;
				
				auto instance_composition = entry_composition.second;
				
				std::cout << "composition name " << instance_composition.name << OUTENDL;
				std::cout << "composition text " << instance_composition.text << OUTENDL;
				std::cout << "composites size " << instance_composition.composites.size() << OUTENDL; 
				
				for(auto entry_composite : instance_composition.composites)
				{
					std::cout << "entry name, planar_def " << entry_composite.first << OUTENDL;
					
					auto instance_planar = entry_composite.second;
					
					std::cout << "planar_def description " 
					<< instance_planar.name << " " 
					<< instance_planar.text << " x "
					<< instance_planar.x << " y "
					<< instance_planar.y << " width "
					<< instance_planar.width << " height "
					<< instance_planar.height << OUTENDL;
				}
			}

			return;
		}

		auto build_interactive_model(type_text_keyvalues_map& instance_current_values) -> void
		{
			//std::cout << "building model, total values " << instance_current_values.size() << OUTENDL;

			type_principle_map_key item_type_desc;
			
			for(auto key_value_entry : instance_current_values)
			{
				auto current_type_desc = get_interactive_def_primary_key(key_value_entry.first, instance_interaction_def_primary_keys);

				if(current_type_desc.first != interaction_def_type::interaction_def_type_none)
				{
					item_type_desc = current_type_desc;

					break;
				}				
			}

			if(item_type_desc.first == interaction_def_type::interaction_def_type_composition)
			{
				//std::cout << "building model for composition" << OUTENDL;
				
				auto name = instance_current_values[item_type_desc.second];

				composition instance_composition;

				if(instance_interaction_models.count(name) > 0)
				{
					//std::cout << "found existing composition model" << OUTENDL;
					instance_composition = instance_interaction_models[name];
				}
				else
				{
					//std::cout << "adding values to composition model" << OUTENDL;
					instance_composition.name = instance_current_values[item_type_desc.second];
					instance_composition.text = instance_current_values["context_phrase"];
				}
				
				/*Single space marks a composition that has been reserved.
				Such is the case when the descendants from the JsonCpp API are read in first.
				Since the JsonCpp API lists items in alphabetical order instead of the actual order,
					the reassembly has to occur in an order independent way.
				Values from the most recent placeholder will be transfered to this instance.
				*/
				//std::cout << "total interaction models " << instance_interaction_models.count(" ") << OUTENDL;

				while(instance_interaction_models[" "].composites.size() > 0)
				{
					//std::cout << "iteration, transferring composites" << OUTENDL;

					composition& placeholder_instance_composition = instance_interaction_models[" "];

					/*Even though the elements are sometimes in a different order
						due to the way the JsonCpp API presents the data,
						it will not matter in the case since the placement is geometric in nature.
					*/
					for(auto composite_entry : placeholder_instance_composition.composites)
					{
						instance_composition.composites.insert(composite_entry);
					}

					placeholder_instance_composition.composites.clear();
				}

				instance_interaction_models.emplace(instance_composition.name, instance_composition);
			}
			else if(item_type_desc.first == interaction_def_type::interaction_def_type_planar_def)
			{
				//std::cout << "building model for planar" << OUTENDL;
				
				composition& instance_composition = instance_interaction_models[" "];

				auto name = instance_current_values[item_type_desc.second];

				planar_def instance_planar_def;

				instance_planar_def.name = name;
				instance_planar_def.text = instance_current_values["planar_phrase"];
				instance_planar_def.x = std::stof(instance_current_values["x"]);
				instance_planar_def.y = std::stof(instance_current_values["y"]);
				instance_planar_def.width = std::stof(instance_current_values["width"]);
				instance_planar_def.height = std::stof(instance_current_values["height"]);

				instance_composition.composites.emplace(instance_planar_def.name, instance_planar_def);
			}

			return;
		}

		auto translate_json_node_to_planar(const Json::Value& instance_node) -> void
		{
			for(const auto& instance_current_node : instance_node)
			{
				const bool is_object = instance_current_node.isObject();

				/*JsonCpp API does not list member names alongside values so we filter on object type only.*/
				if(is_object && !instance_current_node.empty())
				{
					type_text_keyvalues_map instance_values;

					const auto& instance_member_names = instance_current_node.getMemberNames();

					for(const auto& member_name : instance_member_names)
					{
						std::cout << " processing :" << member_name;

						const auto& instance_member_node = instance_current_node[member_name];

						std::cout << " Json node descendants :" << instance_member_node.size();
						std::cout << " Json node type :" << get_jsoncpp_value_type_name(instance_member_node.type());
						std::cout << " Json node empty? :" << instance_member_node.empty() << OUTENDL;
						
						const bool is_value_type = get_json_node_is_value_type(instance_member_node);
						const bool is_array = instance_member_node.isArray();

						if(is_value_type)
						{
							std::string member_value = instance_member_node.asString();

							instance_values[member_name] = member_value;
						}
						else if(is_array)
						{
							translate_json_node_to_planar(instance_member_node);
						}
					}

					build_interactive_model(instance_values);

					translate_json_node_to_planar(instance_current_node);
				}
			}

			return;
		}
		
		auto configure_interaction_models() -> void
		{
			/*
				Defining a user interface with JSON
				https://developer.gnome.org/clutter-cookbook/stable/script-ui.html

				JsonCpp Documentation
				http://open-source-parsers.github.io/jsoncpp-docs/doxygen/index.html
			*/
			instance_interaction_def_primary_keys["context_elemid"] = interaction_def_type::interaction_def_type_composition;
			instance_interaction_def_primary_keys["planar_elemid"] = interaction_def_type::interaction_def_type_planar_def;

			std::string ui_spec = 
			"[		\
				{	\
					\"context_elemid\": \"loginscreen\", \
					\"context_phrase\": \"Login Screen\", \
					 \"composites\": [\
						{ \
							\"planar_elemid\": \"username\", \
							\"planar_phrase\": \"User name\", \
							\"x\": 100.00, \
							\"y\": 200.00, \
							\"width\": 300.00, \
							\"height\": 400.00 \
						},\
						{ \
							\"planar_elemid\": \"password\", \
							\"planar_phrase\": \"Password\", \
							\"x\": 100.00, \
							\"y\": 300.00, \
							\"width\": 300.00, \
							\"height\": 400.00 \
						}\
					]\
				}	\
			]		\
			";

			Json::Value spec_data;
			Json::Reader spec_reader;

			spec_reader.parse(ui_spec, spec_data, false);

			translate_json_node_to_planar(spec_data);

			instance_interaction_models.erase(" ");

			return;
		}

		auto configure_interaction() -> void
		{
			composition instance_composition;

			instance_interaction_models.emplace(" ", instance_composition);

			configure_interaction_context(ICTX_DEFAULT_EXTENT, ICTX_DEFAULT_TITLE);

			configure_interaction_models();

			output_model_to_console();
			
			return;
		};

		auto execute() -> int
		{
			configure_interaction();
			auto return_value = execute_interaction();

			return return_value;
		}
	}
}

auto main() -> int
{
	auto return_value = gautier::program::execute();

	return return_value;
}

/*
	Edit log

	Compile sizes

		173248 Feb 23 00:12 main.o	debug
		105918 Feb 23 00:12 assembled executable	debug

		173264 Feb 23 00:43 main.o	debug
		105891 Feb 23 00:44 assembled executable	debug

		173264 Feb 23 00:52 main.o	debug
		105891 Feb 23 00:52 assembled executable	debug

		181688 Feb 23 01:13 main.o	debug
		113467 Feb 23 01:14 assembled executable	debug

		206360 Feb 23 13:25 main.o	debug
		123092 Feb 23 13:25 assembled executable	debug

		241752 Feb 23 20:39 main.o	debug
		143825 Feb 23 20:39 assembled executable	debug

		315736 Feb 24 17:44 main.o	debug
		182628 Feb 24 17:44 assembled executable	debug

		325240 Feb 25 08:12 main.o	debug
		190548 Feb 25 08:12 assembled executable	debug

		425152 Mar  9 18:38 main.o	debug
		250633 Mar  9 18:38 assembled executable	debug

		214916 Mar 25 02:10 main.o	debug		code size decline
		172052 Mar 25 02:10 assembled executable	debug

		1303512 Mar 25 13:24 jsonlib.o	debug
		 334996 Mar 25 13:24 program.o	debug
		1107965 Mar 25 13:24 assembled executable	debug

		1303512 Mar 27 02:00 jsonlib.o	debug
		 732284 Mar 27 02:00 program.o	debug
		1370581 Mar 27 02:00 assembled executable	debug

		1303512 Mar 27 14:34 jsonlib.o	debug
		 767024 Mar 27 14:34 program.o	debug
		1396436 Mar 27 14:34 assembled executable	debug

*/
