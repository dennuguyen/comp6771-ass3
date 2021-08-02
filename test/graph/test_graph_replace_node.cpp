// Author: Dan Nguyen
// Last Modified Date: 2021/08/02
//
// This test file contains test cases for replace_node function of gdwg::graph.

#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>
#include <stdexcept>

TEST_CASE("Replacing a node should replace the node's value") {
	SECTION("Replacing node with string data type") {
		auto g = gdwg::graph<std::string, int>({"A"});
		g.replace_node("A", "B");
		CHECK(g.nodes() == std::vector<std::string>({"B"}));
	}

	SECTION("Replacing node with integer data type") {
		auto g = gdwg::graph<int, int>({3});
		g.replace_node(3, 4);
		CHECK(g.nodes() == std::vector<int>({4}));
	}

	SECTION("Replacing node with edges") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C"});
		g.insert_edge("A", "B", 1);
		g.insert_edge("A", "C", 2);
		g.replace_node("A", "D");
		CHECK(g.find("D", "B", 1) != g.end());
		CHECK(g.find("D", "C", 2) != g.end());
	}
}

TEST_CASE("Successfully replacing a node should return true") {
	SECTION("Replacing node with string data type") {
		auto g = gdwg::graph<std::string, int>({"A"});
		CHECK(g.replace_node("A", "B") == true);
	}

	SECTION("Replacing node with integer data type") {
		auto g = gdwg::graph<int, int>({3});
		CHECK(g.replace_node(3, 4) == true);
	}

	SECTION("Replacing node with edges") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C"});
		g.insert_edge("A", "B", 1);
		g.insert_edge("A", "C", 2);
		CHECK(g.replace_node("A", "D") == true);
	}
}

TEST_CASE("Unsuccessfully replacing a node should return false") {
	SECTION("Replacing old data with itself") {
		auto g = gdwg::graph<std::string, int>({"A"});
		CHECK(g.replace_node("A", "A") == false);
	}

	SECTION("Replacing old data with another existing node") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		CHECK(g.replace_node("A", "B") == false);
	}
}

TEST_CASE("Replacing a node without an existing node to replace should throw") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<std::string, int>();
		CHECK_THROWS_AS(g.replace_node("A", "B"), std::runtime_error);
	}

	SECTION("Non-existent node") {
		auto g = gdwg::graph<std::string, int>({"A"});
		CHECK_THROWS_AS(g.replace_node("B", "A"), std::runtime_error);
	}
}