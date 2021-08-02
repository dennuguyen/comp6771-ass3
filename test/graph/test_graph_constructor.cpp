// Author: Dan Nguyen
// Last Modified Date: 2021/08/02
//
// This test file contains test cases for all the implemented constructors of gdwg::graph.

#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <set>
#include <vector>

TEST_CASE("No-parameters constructor should initialise empty graph") {
	SECTION("int nodes and string edges") {
		auto g = gdwg::graph<int, std::string>();
		CHECK(g.empty() == true);
	}

	SECTION("string nodes and double edges") {
		auto g = gdwg::graph<std::string, double>();
		CHECK(g.empty() == true);
	}

	SECTION("bool nodes and char edges") {
		auto g = gdwg::graph<bool, char>();
		CHECK(g.empty() == true);
	}
}

TEST_CASE("Initialiser-list constructor should create graph with values from initialiser list") {
	SECTION("Empty initialiser list") {
		auto g = gdwg::graph<int, std::string>({});
		CHECK(g.empty() == true);
	}

	SECTION("Initialiser list with ints") {
		auto g = gdwg::graph<int, std::string>({2, 3, 4});
		CHECK(g.is_node(2) == true);
		CHECK(g.is_node(3) == true);
		CHECK(g.is_node(4) == true);
	}

	SECTION("Initialiser list with doubles") {
		auto g = gdwg::graph<double, std::string>({42.1, -5.4392, 35.1231, -5.4});
		CHECK(g.is_node(42.1) == true);
		CHECK(g.is_node(-5.4392) == true);
		CHECK(g.is_node(35.1231) == true);
		CHECK(g.is_node(-5.4) == true);
	}

	SECTION("Initialiser list with chars") {
		auto g = gdwg::graph<char, std::string>({'3', 'c', 'C', ' ', '\n', '\0', 'q', '~'});
		CHECK(g.is_node('3') == true);
		CHECK(g.is_node('c') == true);
		CHECK(g.is_node('C') == true);
		CHECK(g.is_node(' ') == true);
		CHECK(g.is_node('\n') == true);
		CHECK(g.is_node('\0') == true);
		CHECK(g.is_node('q') == true);
		CHECK(g.is_node('~') == true);
	}

	SECTION("Initialiser list with strings") {
		auto g = gdwg::graph<std::string, std::string>({"kj3n2kr1", "", "\n", "\""});
		CHECK(g.is_node("kj3n2kr1") == true);
		CHECK(g.is_node("") == true);
		CHECK(g.is_node("\n") == true);
		CHECK(g.is_node("\"") == true);
	}
}

TEST_CASE("Iterator constructor should create graph with [first, last) iterator values") {
	SECTION("Initialiser list iterators for an empty range") {
		auto il = std::initializer_list<int>();
		auto g = gdwg::graph<int, double>(il.begin(), il.end());
		CHECK(g.empty() == true);
	}

	SECTION("Initialiser list iterators for a full range") {
		auto il = {300000000, 5, 1, 912, -4, -335, -1, 0, 81};
		auto g = gdwg::graph<int, double>(il.begin(), il.end());
		CHECK(g.is_node(300000000) == true);
		CHECK(g.is_node(5) == true);
		CHECK(g.is_node(1) == true);
		CHECK(g.is_node(912) == true);
		CHECK(g.is_node(-4) == true);
		CHECK(g.is_node(-335) == true);
		CHECK(g.is_node(-1) == true);
		CHECK(g.is_node(0) == true);
		CHECK(g.is_node(81) == true);
	}

	SECTION("Initialiser list iterators for a subrange including start and excluding end") {
		auto il = {"first", "second", "third", "fourth", "fifth", "sixth"};
		auto g = gdwg::graph<std::string, double>(il.begin(), il.begin() + 3);
		CHECK(g.is_node("first") == true);
		CHECK(g.is_node("second") == true);
		CHECK(g.is_node("third") == true);
		CHECK(g.is_node("fourth") == false);
		CHECK(g.is_node("fifth") == false);
		CHECK(g.is_node("sixth") == false);
	}

	SECTION("Initialiser list iterators for a subrange excluding start and including end") {
		auto il = {"first", "second", "third", "fourth", "fifth", "sixth"};
		auto g = gdwg::graph<std::string, double>(il.begin() + 4, il.end());
		CHECK(g.is_node("first") == false);
		CHECK(g.is_node("second") == false);
		CHECK(g.is_node("third") == false);
		CHECK(g.is_node("fourth") == false);
		CHECK(g.is_node("fifth") == true);
		CHECK(g.is_node("sixth") == true);
	}

	SECTION("Initialiser list iterators for a subrange excluding start and excluding end") {
		auto il = {"first", "second", "third", "fourth", "fifth", "sixth"};
		auto g = gdwg::graph<std::string, double>(il.begin() + 2, il.begin() + 5);
		CHECK(g.is_node("first") == false);
		CHECK(g.is_node("second") == false);
		CHECK(g.is_node("third") == true);
		CHECK(g.is_node("fourth") == true);
		CHECK(g.is_node("fifth") == true);
		CHECK(g.is_node("sixth") == false);
	}
}

TEST_CASE("Iterator constructor should create graph from various STL containers") {
	SECTION("Array iterators for some range") {
		auto arr = std::array<double, 3>({3.415, -49232.0, 4932.491238});
		auto g = gdwg::graph<double, int>(arr.begin(), arr.end());
		CHECK(g.is_node(3.415) == true);
		CHECK(g.is_node(-49232.0) == true);
		CHECK(g.is_node(4932.491238) == true);
	}

	SECTION("Forward list iterators for some range") {
		auto fl = std::forward_list<bool>({true, false});
		auto g = gdwg::graph<bool, int>(fl.begin(), fl.end());
		CHECK(g.is_node(true) == true);
		CHECK(g.is_node(false) == true);
	}

	SECTION("Deque iterators for some range") {
		auto deq = std::deque<double>({3.415, -49232.0, 4932.491238});
		auto g = gdwg::graph<double, int>(deq.begin(), deq.end());
		CHECK(g.is_node(3.415) == true);
		CHECK(g.is_node(-49232.0) == true);
		CHECK(g.is_node(4932.491238) == true);
	}

	SECTION("Vector iterators for some range") {
		auto vec = std::vector<std::size_t>({1, 2, 3});
		auto g = gdwg::graph<std::size_t, int>(vec.begin(), vec.end());
		CHECK(g.is_node(1) == true);
		CHECK(g.is_node(2) == true);
		CHECK(g.is_node(3) == true);
	}

	SECTION("Set iterators for some range") {
		auto s = std::set<unsigned int>({12312490, 253849583});
		auto g = gdwg::graph<unsigned int, int>(s.begin(), s.end());
		CHECK(g.is_node(12312490) == true);
		CHECK(g.is_node(253849583) == true);
	}

	SECTION("List iterators for some range") {
		auto li = std::list<std::string>({"ieo12j 1jr 3kr1oie j1lk ", "fej2oi3i2oj1sfklsa;2;1"});
		auto g = gdwg::graph<std::string, int>(li.begin(), li.end());
		CHECK(g.is_node("ieo12j 1jr 3kr1oie j1lk ") == true);
		CHECK(g.is_node("fej2oi3i2oj1sfklsa;2;1") == true);
	}
}

TEST_CASE("Constructors should discard duplicate values") {
	SECTION("Duplicate values in initialiser list constructor") {
		auto g = gdwg::graph<int, int>({1, 1, 3, 4, 8, 8, 3});
		CHECK(g.nodes() == std::vector<int>({1, 3, 4, 8}));
	}

	SECTION("Duplicate values in iterator constructor") {
		auto vec = std::vector<std::string>({"b", "a", "b", "d", "c", "c", "d", "e", "a", "e"});
		auto g = gdwg::graph<std::string, int>(vec.begin(), vec.end());
		CHECK(g.nodes() == std::vector<std::string>({"a", "b", "c", "d", "e"}));
	}
}

TEST_CASE("Copy constructor should create graph with same values as original") {
	SECTION("Copy empty graph") {
		auto g1 = gdwg::graph<int, int>();
		auto g2 = gdwg::graph<int, int>(g1);
		CHECK(g2.empty() == true);
	}

	SECTION("Copy graph with only nodes") {
		auto g1 = gdwg::graph<int, int>({3, 4, 6, 8, -4, -1, 0});
		auto g2 = gdwg::graph<int, int>(g1);
		CHECK(g2.is_node(3) == true);
		CHECK(g2.is_node(4) == true);
		CHECK(g2.is_node(6) == true);
		CHECK(g2.is_node(8) == true);
		CHECK(g2.is_node(-4) == true);
		CHECK(g2.is_node(-1) == true);
		CHECK(g2.is_node(0) == true);
	}

	SECTION("Copy graph with nodes and edges") {
		auto g1 = gdwg::graph<int, int>({3, 4, 6});
		g1.insert_edge(3, 4, 1);
		auto g2 = gdwg::graph<int, int>(g1);
		CHECK(g2.is_node(3) == true);
		CHECK(g2.is_node(4) == true);
		CHECK(g2.is_node(6) == true);
		CHECK(g2.is_connected(3, 4) == true);
	}
}

TEST_CASE("Copy constructor should not modify original") {
	SECTION("Copy empty graph") {
		auto g1 = gdwg::graph<int, int>();
		auto g2 = gdwg::graph<int, int>(g1);
		g2.insert_node(483958394);
		CHECK(g1.empty() == true);
	}

	SECTION("Copy graph with only nodes") {
		auto g1 = gdwg::graph<int, int>({3, 4, 6});
		auto g2 = gdwg::graph<int, int>(g1);
		g2.insert_node(2);
		g2.erase_node(3);
		CHECK(g1.is_node(3) == true);
		CHECK(g1.is_node(4) == true);
		CHECK(g1.is_node(6) == true);
		CHECK(g1.is_node(2) == false);
	}

	SECTION("Copy graph with nodes and edges") {
		auto g1 = gdwg::graph<int, int>({3, 4, 6});
		g1.insert_edge(3, 4, 1);
		auto g2 = gdwg::graph<int, int>(g1);
		g2.insert_node(2);
		g2.erase_node(3);
		g2.insert_edge(3, 6, 10);
		CHECK(g1.is_node(3) == true);
		CHECK(g1.is_node(4) == true);
		CHECK(g1.is_node(6) == true);
		CHECK(g1.is_node(2) == false);
		CHECK(g1.is_connected(3, 4) == true);
	}
}

TEST_CASE("Move constructor should create graph with the values of the original") {
	SECTION("Move empty graph") {
		auto g1 = gdwg::graph<int, int>({});
		auto g2 = gdwg::graph<int, int>(std::move(g1));
		CHECK(g2.empty() == true);
	}

	SECTION("Move graph with only nodes") {
		auto g1 = gdwg::graph<int, int>({3, 4, 6});
		auto g2 = gdwg::graph<int, int>(std::move(g1));
		CHECK(g2.is_node(3) == true);
		CHECK(g2.is_node(4) == true);
		CHECK(g2.is_node(6) == true);
	}

	SECTION("Move graph with nodes and edges") {
		auto g1 = gdwg::graph<int, int>({3, 4, 6});
		g1.insert_edge(3, 4, 1);
		g1.insert_edge(3, 6, 1);
		auto g2 = gdwg::graph<int, int>(std::move(g1));
		CHECK(g2.is_node(3) == true);
		CHECK(g2.is_node(4) == true);
		CHECK(g2.is_node(6) == true);
		CHECK(g2.is_connected(3, 4) == true);
		CHECK(g2.is_connected(3, 6) == true);
	}
}