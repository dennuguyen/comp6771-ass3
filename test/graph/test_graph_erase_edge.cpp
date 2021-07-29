#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Erasing edge should remove edge in direction of source to destination nodes") {
	SECTION("Graph with existing value type") {}
	SECTION("Graph with cycle between specified nodes") {}
	SECTION("Graph with forests") {}
}

TEST_CASE("Successfully erasing an edge with value type should return true") {
	SECTION("Graph with existing value type") {}
	SECTION("Graph with no existing value type") {}
	SECTION("Graph with cycle between specified nodes") {}
	SECTION("Graph with forests") {}
}

TEST_CASE("Unsuccessfully erasing an edge value type should return false") {
	SECTION("Graph with existing value type") {}
	SECTION("Graph with no existing value type") {}
	SECTION("Graph with cycle between specified nodes") {}
	SECTION("Graph with forests") {}
}

TEST_CASE("Erasing edge with iterator should remove pointed-to specified nodes and edge") {
	SECTION("Graph with existing value type") {}
	SECTION("Graph with no existing value type") {}
	SECTION("Graph with cycle between specified nodes") {}
	SECTION("Graph with forests") {}
}

TEST_CASE("Erasing edge with start, end iterators should remove range of edges in [start, end)") {
	SECTION("Graph with existing value type in range") {}
	SECTION("Graph with no existing value type in range") {}
	SECTION("Graph with cycle within range") {}
	SECTION("Graph with forests") {}
}

TEST_CASE("Erasing edge with non-existent edge should do nothing") {
	SECTION("Erasing by value type") {}
	SECTION("Erasing by iterator") {}
	SECTION("Erasing by iterator range") {}
}

TEST_CASE("Erasing edge with any iterators should return iterator to after last erased element") {
	SECTION("Graph with existing value type") {}
	SECTION("Graph with cycle between specified nodes") {}
	SECTION("Graph with existing value type in range") {}
	SECTION("Graph with cycle within range") {}
	SECTION("Graph with forests") {}
}

TEST_CASE("Erasing edge with non-existent nodes should throw") {
	SECTION("Empty graph") {}
	SECTION("Invalid source node") {}
	SECTION("Invalid destination node") {}
}