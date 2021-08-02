// Author: Dan Nguyen
// Last Modified Date: 2021/08/02
//
// This test file contains test cases for the clear function of gdwg::graph.

#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Clear should remove all nodes and edges from a graph") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<std::string, int>();
		REQUIRE(g.empty() == true);
		g.clear();
		CHECK(g.empty() == true);
	}

	SECTION("Graph with 1 node") {
		auto g = gdwg::graph<std::string, int>({"hello"});
		REQUIRE(g.empty() == false);
		g.clear();
		CHECK(g.empty() == true);
	}

	SECTION("Graph with 4 nodes") {
		auto g = gdwg::graph<std::string, int>({"", "1", "2", "3"});
		REQUIRE(g.empty() == false);
		g.clear();
		CHECK(g.empty() == true);
	}

	SECTION("Graph with 10 nodes") {
		auto g = gdwg::graph<std::string, int>({"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"});
		REQUIRE(g.empty() == false);
		g.clear();
		CHECK(g.empty() == true);
	}
}
