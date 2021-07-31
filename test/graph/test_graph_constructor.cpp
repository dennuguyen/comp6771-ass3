#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

#include <initializer_list>
#include <iostream>

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
		CHECK(g.empty() == false);
		CHECK(g.is_node(2) == true);
		CHECK(g.is_node(3) == true);
		CHECK(g.is_node(4) == true);
	}

	SECTION("Initialiser list with doubles") {
		auto g = gdwg::graph<double, std::string>({42.1, -5.4392, 35.1231, -5.4});
		CHECK(g.empty() == false);
		CHECK(g.is_node(42.1) == true);
		CHECK(g.is_node(-5.4392) == true);
		CHECK(g.is_node(35.1231) == true);
		CHECK(g.is_node(-5.4) == true);
	}

	SECTION("Initialiser list with chars") {
		auto g = gdwg::graph<char, std::string>({'3', 'c', 'C', ' ', '\n', '\0', 'q', '~'});
		CHECK(g.empty() == false);
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
		auto g = gdwg::graph<std::string, std::string>({"kj3n2kr1", "", "2\0mk", "\""});
		CHECK(g.empty() == false);
		CHECK(g.is_node("kj3n2kr1") == true);
		CHECK(g.is_node("") == true);
		CHECK(g.is_node("2\0mk") == true);
		CHECK(g.is_node("\"") == true);
	}
}

TEST_CASE("Iterator constructor should create graph with [start, end) values") {
	SECTION("Initialiser list iterators for an empty range") {
		auto il = std::initializer_list<int>();
		auto g = gdwg::graph<int, double>(il.begin(), il.end());
		CHECK(g.empty() == true);
	}

	SECTION("Initialiser list iterators for a full range") {
		auto il = {300000000, 5, 1, 912, -4, -335, -1, 0, 81};
		auto g = gdwg::graph<int, double>(il.begin(), il.end());
		CHECK(g.empty() == false);
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
		CHECK(g.empty() == false);
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
		CHECK(g.empty() == false);
		CHECK(g.is_node("first") == false);
		CHECK(g.is_node("second") == false);
		CHECK(g.is_node("third") == false);
		CHECK(g.is_node("fourth") == false);
		CHECK(g.is_node("fifth") == true);
		CHECK(g.is_node("sixth") == true);
	}

	SECTION("Initialiser list iterators for a subrange excluding start and excluding end") {
		auto il ={"first", "second", "third", "fourth", "fifth", "sixth"};
		auto g = gdwg::graph<std::string, double>(il.begin() + 2, il.begin() + 5);
		CHECK(g.empty() == false);
		CHECK(g.is_node("first") == false);
		CHECK(g.is_node("second") == false);
		CHECK(g.is_node("third") == true);
		CHECK(g.is_node("fourth") == true);
		CHECK(g.is_node("fifth") == true);
		CHECK(g.is_node("sixth") == false);
	}

	SECTION("Array iterators for some range") {}
	SECTION("Stack iterators for some range") {}
	SECTION("Queue iterators for some range") {}
	SECTION("Vector iterators for some range") {}
	SECTION("Map iterators for some range") {}
	SECTION("Set iterators for some range") {}
	SECTION("List iterators for some range") {}
}

TEST_CASE("Copy constructor should create graph with same values as original") {
	SECTION("Copy empty graph") {}
	SECTION("Copy graph with only nodes") {}
	SECTION("Copy graph with nodes and edges") {}
	SECTION("Copy graph with cycle") {}
	SECTION("Copy graph with tree") {}
}

TEST_CASE("Copy constructor should not modify original") {
	SECTION("Copy empty graph") {}
	SECTION("Copy graph with only nodes") {}
	SECTION("Copy graph with nodes and edges") {}
	SECTION("Copy graph with cycle") {}
	SECTION("Copy graph with tree") {}
}

TEST_CASE("Move constructor should create graph with the values of the original") {
	SECTION("Move empty graph") {}
	SECTION("Move graph with only nodes") {}
	SECTION("Move graph with nodes and edges") {}
	SECTION("Move graph with cycle") {}
	SECTION("Move graph with tree") {}
}