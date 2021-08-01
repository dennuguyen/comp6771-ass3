#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>
#include <stdexcept>

TEST_CASE("Merge-replacing a node should replace the node's value and merge duplicated edges") {
	SECTION("Simple merge replacement") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C", "D"});
		g.insert_edge("A", "B", 1);
		g.insert_edge("A", "C", 2);
		g.insert_edge("A", "D", 3);
		g.merge_replace_node("A", "B");
		CHECK(g.find("B", "B", 1) != g.end());
		CHECK(g.find("B", "C", 2) != g.end());
		CHECK(g.find("B", "D", 3) != g.end());
	}

	SECTION("Merge replacement with duplicate edges") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C", "D"});
		g.insert_edge("A", "B", 1);
		g.insert_edge("A", "C", 2);
		g.insert_edge("A", "D", 3);
		g.insert_edge("B", "B", 1);
		g.merge_replace_node("A", "B");
		CHECK(g.find("B", "B", 1) != g.end());
		CHECK(g.find("B", "C", 2) != g.end());
		CHECK(g.find("B", "D", 3) != g.end());
	}
}

TEST_CASE("Merge-replacing a node without an existing node to replace should throw") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<std::string, int>();
		CHECK_THROWS_AS(g.replace_node("A", "B"), std::runtime_error);
	}

	SECTION("Non-existent source node") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		CHECK_THROWS_AS(g.replace_node("C", "A"), std::runtime_error);
	}

	SECTION("Non-existent destination node") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		CHECK_THROWS_AS(g.replace_node("B", "C"), std::runtime_error);
	}
}