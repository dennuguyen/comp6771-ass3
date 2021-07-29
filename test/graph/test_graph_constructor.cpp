#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

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
	SECTION("Initialiser list with ints") {}
	SECTION("Initialiser list with chars") {}
	SECTION("Initialiser list with bools") {}
	SECTION("Initialiser list with strings") {}
	SECTION("Initialiser list with doubles") {}
}

TEST_CASE("Iterator constructor should create graph with [start, end) values") {
	SECTION("Initialiser list iterators for a full range") {}
	SECTION("Initialiser list iterators for a subrange including start and excluding end") {}
	SECTION("Initialiser list iterators for a subrange excluding start and including end") {}
	SECTION("Initialiser list iterators for a subrange excluding start and excluding end") {}
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