#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>
#include <stdexcept>

TEST_CASE("is_connected() should return true if there is a directed edge between two given nodes") {
	SECTION("Graph with 2 connected nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C", "D"});
		REQUIRE(g.insert_edge("B", "D", 10) == true);
		CHECK(g.is_connected("B", "D") == true);
	}
}

TEST_CASE("is_connected() should be directional") {
	SECTION("Graph with 2 connected nodes in a single direction") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		REQUIRE(g.insert_edge("A", "B", 10) == true);
		CHECK(g.is_connected("A", "B") == true);
		CHECK(g.is_connected("B", "A") == false);
	}

	SECTION("Graph with 2 connected nodes in both directions") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		REQUIRE(g.insert_edge("A", "B", 10) == true);
		REQUIRE(g.insert_edge("B", "A", 10) == true);
		CHECK(g.is_connected("A", "B") == true);
		CHECK(g.is_connected("B", "A") == true);
	}
}

TEST_CASE("is_connected() should return false if there is no edge between two given nodes") {
	SECTION("Graph with 2 disconnected nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		CHECK(g.is_connected("A", "B") == false);
		CHECK(g.is_connected("B", "A") == false);
	}
}

TEST_CASE("is_connected() should throw if the specified nodes does not exist") {
	SECTION("Non-existent source node") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C"});
		CHECK_THROWS_AS(g.is_connected("D", "B"), std::runtime_error);
	}

	SECTION("Non-existent destination node") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C"});
		CHECK_THROWS_AS(g.is_connected("A", "D"), std::runtime_error);
	}
}
