// Author: Dan Nguyen
// Last Modified Date: 2021/08/02
//
// This test file contains test cases for the copy and move assignments of gdwg::graph.

#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Copy assignment should copy graph with same values as original") {
	SECTION("Copy assign empty graph") {
		auto g1 = gdwg::graph<int, int>();
		auto g2 = gdwg::graph<int, int>({0, -1, -2});
		g2 = g1;
		CHECK(g2.empty() == true);
	}

	SECTION("Copy assign graph with only nodes") {
		auto g1 = gdwg::graph<int, int>({3, 4, 6});
		auto g2 = gdwg::graph<int, int>({0, -1, -2});
		g2 = g1;
		CHECK(g2.is_node(3) == true);
		CHECK(g2.is_node(4) == true);
		CHECK(g2.is_node(6) == true);
	}

	SECTION("Copy assign graph with nodes and edges") {
		auto g1 = gdwg::graph<int, int>({3, 4, 6});
		g1.insert_edge(3, 4, 1);
		g1.insert_edge(3, 6, 1);
		REQUIRE(g1.is_connected(3, 4) == true);
		REQUIRE(g1.is_connected(3, 6) == true);
		auto g2 = gdwg::graph<int, int>({0, -1, -2});
		g2 = g1;
		CHECK(g2.is_node(3) == true);
		CHECK(g2.is_node(4) == true);
		CHECK(g2.is_node(6) == true);
		CHECK(g2.is_connected(3, 4) == true);
		CHECK(g2.is_connected(3, 6) == true);
	}
}

TEST_CASE("Copy assignment should not modify original") {
	SECTION("Copy assign empty graph") {
		auto g1 = gdwg::graph<int, int>();
		auto g2 = gdwg::graph<int, int>({0, -1, -2});
		g2 = g1;
		g2.insert_node(3);
		CHECK(g1.empty() == true);
	}

	SECTION("Copy assign graph with only nodes") {
		auto g1 = gdwg::graph<int, int>({3, 4, 6});
		auto g2 = gdwg::graph<int, int>({0, -1, -2});
		g2 = g1;
		g2.clear();
		CHECK(g1.is_node(3) == true);
		CHECK(g1.is_node(4) == true);
		CHECK(g1.is_node(6) == true);
	}

	SECTION("Copy assign graph with nodes and edges") {
		auto g1 = gdwg::graph<int, int>({3, 4, 6});
		g1.insert_edge(3, 4, 1);
		g1.insert_edge(3, 6, 1);
		REQUIRE(g1.is_connected(3, 4) == true);
		REQUIRE(g1.is_connected(3, 6) == true);
		auto g2 = gdwg::graph<int, int>({0, -1, -2});
		g2 = g1;
		CHECK(g1.is_node(3) == true);
		CHECK(g1.is_node(4) == true);
		CHECK(g1.is_node(6) == true);
		CHECK(g1.is_connected(3, 4) == true);
		CHECK(g1.is_connected(3, 6) == true);
	}
}

TEST_CASE("Move assignment should create graph with the values of the original") {
	SECTION("Move assign empty graph") {
		auto g1 = gdwg::graph<int, int>();
		auto g2 = gdwg::graph<int, int>({0, -1, -2});
		g2 = std::move(g1);
		CHECK(g2.empty() == true);
	}

	SECTION("Move assign graph with only nodes") {
		auto g1 = gdwg::graph<int, int>({0, -1, -2});
		auto g2 = gdwg::graph<int, int>();
		g2 = std::move(g1);
		CHECK(g2.is_node(0) == true);
		CHECK(g2.is_node(-1) == true);
		CHECK(g2.is_node(-2) == true);
	}

	SECTION("Move assign graph with nodes and edges") {
		auto g1 = gdwg::graph<int, int>({3, 4, 6});
		g1.insert_edge(3, 4, 1);
		g1.insert_edge(3, 6, 1);
		REQUIRE(g1.is_connected(3, 4) == true);
		REQUIRE(g1.is_connected(3, 6) == true);
		auto g2 = gdwg::graph<int, int>({0, -1, -2});
		g2 = std::move(g1);
		CHECK(g2.is_node(3) == true);
		CHECK(g2.is_node(4) == true);
		CHECK(g2.is_node(6) == true);
		CHECK(g2.is_connected(3, 4) == true);
		CHECK(g2.is_connected(3, 6) == true);
	}
}