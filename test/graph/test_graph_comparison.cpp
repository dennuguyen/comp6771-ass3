#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Comparing two graphs with the same nodes and edges should return true") {
	SECTION("Empty graph") {
		auto g1 = gdwg::graph<std::string, int>();
		auto g2 = gdwg::graph<std::string, int>();
		CHECK(g1 == g2);
	}

	SECTION("Graph with only nodes") {
		auto g1 = gdwg::graph<std::string, int>({"A", "B", "C"});
		auto g2 = gdwg::graph<std::string, int>(g1);
		CHECK(g1 == g2);
	}

	SECTION("Graph with nodes and edges") {
		auto g1 = gdwg::graph<std::string, int>({"A", "B", "C"});
		g1.insert_edge("A", "B", 1);
		g1.insert_edge("A", "C", 1);
		g1.insert_edge("C", "B", 1);
		auto g2 = gdwg::graph<std::string, int>(g1);
		CHECK(g1 == g2);
	}
}

TEST_CASE("Comparing two graphs with any non-equal nodes and edges should return false") {
	SECTION("Empty graph and graph with a node") {
		auto g1 = gdwg::graph<std::string, int>();
		auto g2 = gdwg::graph<std::string, int>({"A"});
		CHECK(g1 != g2);
	}

	SECTION("Graph with only nodes") {
		auto g1 = gdwg::graph<std::string, int>({"A", "B", "C"});
		auto g2 = gdwg::graph<std::string, int>({"A", "E", "C"});
		CHECK(g1 != g2);
	}

	SECTION("Graph with nodes and edges") {
		auto g1 = gdwg::graph<std::string, int>({"A", "B", "C"});
		g1.insert_edge("A", "B", 1);
		g1.insert_edge("A", "C", 1);
		g1.insert_edge("C", "B", 1);
		auto g2 = gdwg::graph<std::string, int>(g1);
		g2.insert_edge("A", "B", 2);
		g2.erase_edge("A", "C", 1);
		CHECK(g1 != g2);
	}
}
