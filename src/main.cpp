/*
  Copyright © 2012 Jesse 'Jeaye' Wilkerson
  See licensing at:
    http://opensource.org/licenses/BSD-3-Clause

  File: main.cpp
  Author: Jesse 'Jeaye' Wilkerson
*/

#include <iostream>
#include <stdint.h>
#include <string>

#include "JsonValue.h"

int32_t main(int32_t argc, char **argv)
{
  /* To start with, create the map and load the file. */
  json_map map;
  map.load_file("doc/getting_started/myFile.json");

  /* We can look at some specify top-level values with "get".
     Notice that "get" returns a reference to the object. */
  std::string &str(map.get<std::string>("str")); // Get "str" as a string reference
  json_array &arr(map.get_array("arr")); // get_array and get_map are convenience functions

  /* A fallback value can also be specified with "get". It does two things:
       1. Helps deduce the type so that an explicit invocation is not needed
       2. Provides a default fallback value, should anything go wrong while accessing
     Note that these functions do NOT return references, due to incompatibilities with the fallback.
     */
  std::string str_copy(map.get("str", "Default boringness")); // Second param is the defaulted string

  /* Delving into maps using dot-notated paths works, too.
     The type can be explicitly specified, or implicit based on the provided fallback.
     */
  std::cout << map.get_for_path<std::string>("person.name") << " has " // No fallback
    << map.get_for_path("person.inventory.coins", 0) << " coins\n"; // Fallback is 0

  /* Iterators work as expected, based on the C++ stdlib. (const and non-const) */
  //for(json_array::const_iterator it(arr.begin()); it != arr.end(); ++it)
    //std::cout << (*it).as<double>() << " ";
}

