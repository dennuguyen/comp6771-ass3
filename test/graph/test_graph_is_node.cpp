// Author: Dan Nguyen
// Last Modified Date: 2021/08/02
//
// This test file contains test cases for the is_node function of gdwg::graph.

#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("is_node() should return true if there exists a node with the given value") {
	SECTION("Graph with 1 node") {
		auto g = gdwg::graph<int, int>({58234321});
		CHECK(g.is_node(58234321) == true);
	}

	SECTION("Graph with 10 nodes") {
		auto g = gdwg::graph<int, int>({3, 4, 6, 8, -4, -1, 0, 23, 53, -59});
		CHECK(g.is_node(3) == true);
		CHECK(g.is_node(4) == true);
		CHECK(g.is_node(6) == true);
		CHECK(g.is_node(8) == true);
		CHECK(g.is_node(-4) == true);
		CHECK(g.is_node(-1) == true);
		CHECK(g.is_node(0) == true);
		CHECK(g.is_node(23) == true);
		CHECK(g.is_node(53) == true);
		CHECK(g.is_node(-59) == true);
	}
}

TEST_CASE("is_node() should work on various data types") {
	SECTION("Nodes with integer data type") {
		auto g = gdwg::graph<int, int>({0});
		CHECK(g.is_node(0) == true);
	}

	SECTION("Nodes with doubles data type") {
		auto g = gdwg::graph<double, int>({5.2438});
		CHECK(g.is_node(5.2438) == true);
	}

	SECTION("Nodes with char data type") {
		auto g = gdwg::graph<char, int>({'c'});
		CHECK(g.is_node('c') == true);
	}

	SECTION("Nodes with string data type") {
		auto g = gdwg::graph<std::string, int>({"kjawfnlk3j22u12jouijne11"});
		CHECK(g.is_node("kjawfnlk3j22u12jouijne11") == true);
	}
}

TEST_CASE("is_node() should return false if there does not exists a node with the given value") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<int, int>();
		CHECK(g.is_node(0) == false);
		CHECK(g.is_node(-234) == false);
		CHECK(g.is_node(-95) == false);
		CHECK(g.is_node(5) == false);
		CHECK(g.is_node(58234321) == false);
	}

	SECTION("Graph with 1 node") {
		auto g = gdwg::graph<int, int>({6});
		CHECK(g.is_node(-6) == false);
		CHECK(g.is_node(4) == false);
		CHECK(g.is_node(5) == false);
		CHECK(g.is_node(66) == false);
	}

	SECTION("Graph with 5 nodes") {
		auto g = gdwg::graph<int, int>({6, 3, 8, 1, 0});
		CHECK(g.is_node(-1) == false);
		CHECK(g.is_node(2) == false);
		CHECK(g.is_node(4) == false);
		CHECK(g.is_node(5) == false);
		CHECK(g.is_node(7) == false);
		CHECK(g.is_node(9) == false);
	}
}