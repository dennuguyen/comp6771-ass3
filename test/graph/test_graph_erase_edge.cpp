// Author: Dan Nguyen
// Last Modified Date: 2021/08/02
//
// This test file contains test cases for the erase_edge function of gdwg::graph.

#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Erasing edge should remove edge in direction of source to destination nodes") {
	SECTION("Graph with existing value type") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 1);
		g.insert_edge("B", "A", 1);
		g.erase_edge("A", "B", 1);
		CHECK(g.is_connected("A", "B") == false);
		CHECK(g.is_connected("B", "A") == true);
	}
}

TEST_CASE("Successfully erasing an edge with value type should return true") {
	SECTION("Graph with existing value type") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 1);
		g.insert_edge("B", "A", 1);
		CHECK(g.erase_edge("A", "B", 1) == true);
	}
}

TEST_CASE("Unsuccessfully erasing an edge value type should return false") {
	SECTION("No edges in both directions") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		CHECK(g.erase_edge("A", "B", 1) == false);
	}

	SECTION("No edge in one direction") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("B", "A", 1);
		CHECK(g.erase_edge("A", "B", 1) == false);
	}
}

TEST_CASE("Erasing edge with iterator should remove pointed-to specified nodes and edge") {
	SECTION("Non-existent edge") {
		auto g = gdwg::graph<std::string, int>();
		CHECK(g.erase_edge(g.begin()) == g.end());
	}

	SECTION("Graph with existing value type") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 1);
		g.insert_edge("A", "B", 2);
		auto it1 = g.find("A", "B", 1);
		auto it2 = g.find("A", "B", 2);
		CHECK(g.erase_edge(it1) == it2);
	}
}

TEST_CASE("Erasing edge with start, end iterators should remove range of edges in [start, end)") {
	SECTION("Non-existent edge") {
		auto g = gdwg::graph<std::string, int>();
		CHECK(g.erase_edge(g.begin(), g.end()) == g.end());
	}

	SECTION("Erasing all edges within range") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 1);
		g.insert_edge("A", "B", 2);
		auto it1 = g.find("A", "B", 1);
		auto it2 = g.find("A", "B", 2);
		CHECK(g.erase_edge(it1, it2) == g.end());
	}
}

TEST_CASE("Erasing edge with non-existent nodes should throw") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<std::string, int>();
		g.erase_edge("A", "B", 1);
	}

	SECTION("Invalid source node") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.erase_edge("C", "B", 1);
	}

	SECTION("Invalid destination node") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.erase_edge("A", "C", 1);
	}
}