#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("is_node() should return true if there is a node with same value_type in the graph") {
	SECTION("Graph with 1 node") {}
	SECTION("Graph with 10 nodes") {}
	SECTION("Graph with cycle of nodes") {}
	SECTION("Graph with tree of nodes") {}
	SECTION("Graph with tree of nodes and edges") {}
	SECTION("Graph with forests of nodes and edges") {}
	SECTION("Node has only outgoing edges") {}
	SECTION("Node has only incoming edges") {}
	SECTION("Node has only both incoming and outgoing edges") {}
	SECTION("Node is isolated from graph") {}
}

TEST_CASE("is_node() should return false if there is no node with same value_type in graph") {
	SECTION("Empty graph") {}
	SECTION("Graph with 1 node") {}
	SECTION("Graph with 10 nodes") {}
	SECTION("Graph with cycle of nodes") {}
	SECTION("Graph with tree of nodes and edges") {}
	SECTION("Graph with forests of nodes and edges") {}
}