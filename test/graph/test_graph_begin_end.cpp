#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Begin should return the first iterator in the graph") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<std::string, std::string>();
		// CHECK(g.begin() )
	}

	SECTION("Graph with node and edge") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 1);
		CHECK(g.is_connected("A", "B") == true);
		// auto it = g.begin();
		// CHECK((*it).to == "A");
		// CHECK((*it).from == "B");
		// CHECK((*it).weight == 1);
	}

	SECTION("Graph with 2 nodes") {}
	SECTION("Graph with 10 nodes") {}
	SECTION("Graph with 100 nodes") {}
	SECTION("Graph after insertion of a new first node") {}
	SECTION("Graph after erasing the first node") {}
	SECTION("Graph with cycle") {}
}

TEST_CASE("End should return the end iterator in the graph") {
	SECTION("Empty graph") {}
	SECTION("Graph with 1 node") {}
	SECTION("Graph with 2 nodes") {}
	SECTION("Graph with 10 nodes") {}
	SECTION("Graph with 100 nodes") {}
	SECTION("Graph after insertion of a new first node") {}
	SECTION("Graph after erasing the first node") {}
	SECTION("Graph with cycle") {}
}
