#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Find should return iterator to value type if equivalent value type exists in graph") {
	SECTION("Graph with some nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C"});
		auto val = gdwg::graph<std::string, int>::value_type({"A", "B", 100});
		g.insert_edge("A", "B", 100);
		g.insert_edge("B", "C", 100);
		auto it = g.find("A", "B", 100);
		CHECK((*it).from == val.from);
		CHECK((*it).to == val.to);
		CHECK((*it).weight == val.weight);
	}
}

TEST_CASE("Find should return end iterator if equivalent value type does not exist in graph") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<std::string, int>();
		CHECK(g.find("A", "B", 100) == g.end());
	}

	SECTION("Graph with some nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C"});
		g.insert_edge("A", "B", 100);
		g.insert_edge("B", "C", 100);
		CHECK(g.find("A", "C", 100) == g.end());
	}
}