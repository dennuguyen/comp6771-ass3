// Author: Dan Nguyen
// Last Modified Date: 2021/08/02
//
// This test file contains test cases for the weights function of gdwg::graph.

#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>
#include <stdexcept>

TEST_CASE("weights() should return ascending-ordered weights between source and destination") {
	SECTION("No edges exist between source and destination") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		CHECK(g.weights("A", "B") == std::vector<int>({}));
	}

	SECTION("1 edge exists between source and destination") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 100);
		CHECK(g.weights("A", "B") == std::vector<int>({100}));
	}

	SECTION("Multiple edges exist between source and destination") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 102);
		g.insert_edge("A", "B", 100);
		g.insert_edge("A", "B", 104);
		g.insert_edge("A", "B", 101);
		g.insert_edge("A", "B", 103);
		CHECK(g.weights("A", "B") == std::vector<int>({100, 101, 102, 103, 104}));
	}

	SECTION("Self-directed edge") {
		auto g = gdwg::graph<std::string, int>({"A"});
		g.insert_edge("A", "A", 100);
		g.insert_edge("A", "A", 99);
		CHECK(g.weights("A", "A") == std::vector<int>({99, 100}));
	}
}

TEST_CASE("weights() should work with various data types") {
	SECTION("Edge with integer data type") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", -9);
		g.insert_edge("A", "B", -100);
		g.insert_edge("A", "B", 68);
		g.insert_edge("A", "B", 0);
		CHECK(g.weights("A", "B") == std::vector<int>({-100, -9, 0, 68}));
	}

	SECTION("Edge with double data type") {
		auto g = gdwg::graph<std::string, double>({"A", "B"});
		g.insert_edge("A", "B", 68.4829);
		g.insert_edge("A", "B", -5.3453889);
		g.insert_edge("A", "B", -10.8492);
		CHECK(g.weights("A", "B") == std::vector<double>({-10.8492, -5.3453889, 68.4829}));
	}

	SECTION("Edge with string data type") {
		auto g = gdwg::graph<std::string, std::string>({"A", "B"});
		g.insert_edge("A", "B", "hello");
		g.insert_edge("A", "B", "peach");
		g.insert_edge("A", "B", "maker");
		CHECK(g.weights("A", "B") == std::vector<std::string>({"hello", "maker", "peach"}));
	}
}

TEST_CASE("weights() should throw if specified nodes does not exist") {
	SECTION("Source node is non-existent") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C"});
		g.insert_edge("A", "B", 100);
		g.insert_edge("B", "C", 100);
		CHECK_THROWS_AS(g.weights("D", "B"), std::runtime_error);
	}

	SECTION("Destination node is non-existent") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C"});
		g.insert_edge("A", "B", 100);
		g.insert_edge("B", "C", 100);
		CHECK_THROWS_AS(g.weights("B", "D"), std::runtime_error);
	}
}