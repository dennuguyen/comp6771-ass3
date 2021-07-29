#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Comparing two graphs with same value_type for all nodes and edges should return true") {
	SECTION("Empty graph") {}
	SECTION("Graph with only nodes") {}
	SECTION("Graph with nodes and edges") {}
	SECTION("Graph with cycles") {}
	SECTION("Graph with trees") {}
}

TEST_CASE("Comparing two graphs with any non-equal value_types should return false") {
	SECTION("Empty graph and graph with a node") {}
	SECTION("Graph with only nodes") {}
	SECTION("Graph with nodes and edges") {}
	SECTION("Graph with cycles") {}
	SECTION("Graph with trees") {}
}
