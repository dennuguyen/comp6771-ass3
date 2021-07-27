#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Default constructor should initialise empty graph") {
	auto g = gdwg::graph<int, std::string>{};
	auto n = 5;
	g.insert_node(n);
	CHECK(g.is_node(n));
}

TEST_CASE("Constructor with initialiser list should create graph with initialiser list values") {}

TEST_CASE("Constructor with start and end iterators should create graph with [start, end) values") {}

TEST_CASE("Copy constructor should instantiate correctly") {}

TEST_CASE("Modifying the copy should not modify copied") {}

TEST_CASE("Move constructor should instantiate correctly") {}