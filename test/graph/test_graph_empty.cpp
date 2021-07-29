#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Empty should be true if there are no nodes and edges in the graph") {
	SECTION("Empty graph") {}
}

TEST_CASE("Empty should be false if there are any nodes in the graph") {
	SECTION("Graph with 1 node") {}
	SECTION("Graph with 10 nodes") {}
}

TEST_CASE("Empty should be false if there are any nodes and edges in the graph") {
	SECTION("Graph with 1 self-directed node") {}
	SECTION("Graph with only a cycle") {}
	SECTION("Graph with only a single-directed tree") {}
}