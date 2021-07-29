#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Connections should return a set of nodes in ascending order from a given node") {
	SECTION("Graph with node with no edges") {}
	SECTION("Graph with 1 node") {}
	SECTION("Graph with 1 node with 1 self-directed edge") {}
	SECTION("Graph with 1 node with many self-directed edges") {}
	SECTION("Graph with a few immediate nodes") {}
	SECTION("Graph with nodes a few levels deep") {}
	SECTION("Graph with cycles") {}
	SECTION("Graph with trees") {}
	SECTION("Graph with forests") {}
}

TEST_CASE("Calling connections with non-existent node should throw") {
	SECTION("Empty graph") {}
	SECTION("Invalid node") {}
}