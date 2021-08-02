// Author: Dan Nguyen
// Last Modified Date: 2021/08/02
//
// This test file contains test cases for the begin and end methods of gdwg::graph.

#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Begin should return the first iterator in the graph") {
	SECTION("Graph with nodes and 1 edge") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 1);
		REQUIRE(g.is_connected("A", "B") == true);
		auto it = g.begin();
		CHECK((*it).to == "A");
		CHECK((*it).from == "B");
		CHECK((*it).weight == 1);
	}

	SECTION("Graph with nodes and multiple edges") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 14);
		g.insert_edge("A", "B", 3);
		g.insert_edge("A", "B", 29);
		REQUIRE(g.is_connected("A", "B") == true);
		auto it = g.begin();
		CHECK((*it).to == "A");
		CHECK((*it).from == "B");
		CHECK((*it).weight == 3);
	}
}

TEST_CASE("Begin to graph with no edges should return the end iterator of the graph") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<std::string, std::string>();
		CHECK(g.begin() == g.end());
	}

	SECTION("Graph with only nodes") {
		auto g = gdwg::graph<std::string, std::string>({"A", "B", "C"});
		CHECK(g.begin() == g.end());
	}
}

TEST_CASE("End should return the end iterator in the graph") {
	SECTION("Graph with node and edge") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 14);
		g.insert_edge("A", "B", 3);
		g.insert_edge("A", "B", 29);
		REQUIRE(g.is_connected("A", "B") == true);
		auto it = g.end();
		--it;
		CHECK((*it).to == "A");
		CHECK((*it).from == "B");
		CHECK((*it).weight == 29);
	}
}
