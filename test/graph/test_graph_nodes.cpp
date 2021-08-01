#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("nodes() should return ascending-ordered sequence of nodes") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<int, int>();
		CHECK(g.nodes() == std::vector<int>({}));
	}

	SECTION("Sorted integers") {
		auto g = gdwg::graph<int, std::string>({1000, -1000, 0, 42, -42});
		CHECK(g.nodes() == std::vector<int>({-1000, -42, 0, 42, 1000}));
	}

	SECTION("Sorted strings") {
		auto g = gdwg::graph<std::string, std::string>({"back", "apple", "bear", "arch", ""});
		CHECK(g.nodes() == std::vector<std::string>({"", "apple", "arch", "back", "bear"}));
	}

	SECTION("Sorted doubles") {
		auto g = gdwg::graph<double, std::string>({-0.000001, -0.01, 0.10, 0.000});
		CHECK(g.nodes() == std::vector<double>({-0.01, -0.000001, 0.000, 0.10}));
	}
}
