#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Erasing node should remove node from graph") {
	SECTION("Graph with 1 node") {}
	SECTION("Graph with node and self-directed edge") {}
	SECTION("Graph with node at root of tree") {}
	SECTION("Graph with node at leaf of tree") {}
	SECTION("Graph with node in cycle") {}
}

TEST_CASE("Erasing non-existent node should do nothing") {
	SECTION("Empty graph") {}
	SECTION("Graph without specified node") {}
}

TEST_CASE("Erasing node should remove all outgoing edges from that node") {}

TEST_CASE("Erasing node should remove all incoming edges to that node") {}

TEST_CASE("Successfully erasing a node should return true") {}

TEST_CASE("Unsuccessfully erasing a node should return false") {
	SECTION("Empty graph") {}
}