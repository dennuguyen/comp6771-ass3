// Author: Dan Nguyen
// Last Modified Date: 2021/08/02
//
// This test file contains test cases for the connections function of gdwg::graph.

#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>
#include <stdexcept>

TEST_CASE("Connections should return a outgoing nodes in ascending order from a given node") {
	SECTION("Graph with 1 node and no edges") {
		auto g = gdwg::graph<std::string, int>({"A"});
		CHECK(g.connections("A") == std::vector<std::string>({}));
	}

	SECTION("Graph with 1 node with some self-directed edges") {
		auto g = gdwg::graph<std::string, int>({"A"});
		g.insert_edge("A", "A", 4);
		g.insert_edge("A", "A", 1);
		g.insert_edge("A", "A", 3);
		g.insert_edge("A", "A", 2);
		CHECK(g.connections("A") == std::vector<std::string>({"A"}));
	}

	SECTION("Graph with a few immediate nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C"});
		g.insert_edge("A", "A", 4);
		g.insert_edge("A", "B", 1);
		g.insert_edge("A", "C", 3);
		g.insert_edge("A", "A", 2);
		CHECK(g.connections("A") == std::vector<std::string>({"A", "B", "C"}));
	}

	SECTION("Graph with incoming/outgoing nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C"});
		g.insert_edge("A", "A", 4);
		g.insert_edge("B", "B", 1);
		g.insert_edge("A", "C", 3);
		g.insert_edge("C", "A", 2);
		g.insert_edge("B", "A", 0);
		CHECK(g.connections("A") == std::vector<std::string>({"A", "C"}));
	}
}

TEST_CASE("Calling connections with non-existent node should throw") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<std::string, int>();
		CHECK_THROWS_AS(g.connections("A"), std::runtime_error);
	}

	SECTION("Invalid node") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C"});
		CHECK_THROWS_AS(g.connections("D"), std::runtime_error);
	}
}