#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Empty should be true if there are no nodes and edges in the graph") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<std::string, std::string>();
		CHECK(g.empty() == true);
	}
}

TEST_CASE("Empty should be false if there are any nodes in the graph") {
	SECTION("Graph with 1 node") {
		auto g = gdwg::graph<std::string, std::string>({""});
		CHECK(g.empty() == false);
	}

	SECTION("Graph with 10 nodes") {
		auto g = gdwg::graph<std::string, std::string>(
		   {"1923", "2532", "5433", "4862", "9995", "6649", "7101", "8234", "9293", "1620"});
		CHECK(g.empty() == false);
	}
}
