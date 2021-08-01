#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>
#include <stdexcept>

TEST_CASE("Replacing a node should replace the node's data") {
	SECTION("Replacing node with string data type") {
		auto g = gdwg::graph<std::string, int>({"A"});
		g.replace_node("A", "B");
		CHECK(g.nodes() == std::vector<std::string>({"B"}));
	}

	SECTION("Replacing node with integer data type") {
		auto g = gdwg::graph<int, int>({3});
		g.replace_node(3, 4);
		CHECK(g.nodes() == std::vector<int>({4}));
	}
}

TEST_CASE("Successfully replacing a node should return true") {
	SECTION("Replacing node with string data type") {
		auto g = gdwg::graph<std::string, int>({"A"});
		CHECK(g.replace_node("A", "B") == true);
	}

	SECTION("Replacing node with integer data type") {
		auto g = gdwg::graph<int, int>({3});
		CHECK(g.replace_node(3, 4) == true);
	}
}

TEST_CASE("Unsuccessfully replacing a node should return false") {
	SECTION("Replacing old data with itself") {
		auto g = gdwg::graph<std::string, int>({"A"});
		CHECK(g.replace_node("A", "A") == false);
	}

	SECTION("Replacing old data with another existing node") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		CHECK(g.replace_node("A", "B") == false);
	}
}

TEST_CASE("Replacing a node without an existing node to replace should throw") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<std::string, int>();
		CHECK_THROWS_AS(g.replace_node("A", "B"), std::runtime_error);
	}

	SECTION("Non-existent node") {
		auto g = gdwg::graph<std::string, int>({"A"});
		CHECK_THROWS_AS(g.replace_node("B", "A"), std::runtime_error);
	}
}