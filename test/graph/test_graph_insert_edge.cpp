#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>
#include <stdexcept>

TEST_CASE("Inserting an edge should create a weighted direction from source to destination nodes") {
	SECTION("Edge between 2 nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 300);
		CHECK(g.find("A", "B", 300) != g.end());
	}

	SECTION("Multiple edges between 2 nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 300);
		g.insert_edge("A", "B", 500);
		g.insert_edge("A", "B", 900);
		CHECK(g.find("A", "B", 300) != g.end());
		CHECK(g.find("A", "B", 500) != g.end());
		CHECK(g.find("A", "B", 900) != g.end());
	}

	SECTION("Self-directed edge") {
		auto g = gdwg::graph<std::string, int>({"A"});
		g.insert_edge("A", "A", 8345391);
		CHECK(g.find("A", "A", 8345391) != g.end());
	}
}

TEST_CASE("Successfully inserting an edge should return true") {
	SECTION("Edge between 2 nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		CHECK(g.insert_edge("A", "B", 300) == true);
	}

	SECTION("Multiple edges between 2 nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		CHECK(g.insert_edge("A", "B", 300) == true);
		CHECK(g.insert_edge("A", "B", 500) == true);
		CHECK(g.insert_edge("A", "B", 900) == true);
	}

	SECTION("Self-directed edge") {
		auto g = gdwg::graph<std::string, int>({"A"});
		g.insert_edge("A", "A", 8345391);
		// CHECK(g.find("A", "A", 8345391) != g.end());
	}
}

TEST_CASE("Unsuccessfully inserting an edge should return false") {
	SECTION("Multiple of same edge between 2 nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 300);
		CHECK(g.insert_edge("A", "B", 300) == false);
	}

	SECTION("Multiple of same edge to self") {
		auto g = gdwg::graph<std::string, int>({"A"});
		g.insert_edge("A", "A", 8345391);
		CHECK(g.insert_edge("A", "A", 8345391) == false);
	}
}

TEST_CASE("Inserting an edge where nodes are non-existent should throw") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<std::string, int>();
		CHECK_THROWS_AS(g.insert_edge("A", "B", 0), std::runtime_error);
	}

	SECTION("Source node is non-existent") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C"});
		CHECK_THROWS_AS(g.insert_edge("WHERE?", "B", 300), std::runtime_error);
	}

	SECTION("Destination node is non-existent") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C"});
		CHECK_THROWS_AS(g.insert_edge("C", "WHERE?", 300), std::runtime_error);
	}
}

TEST_CASE("Inserting an edge should be directional") {
	SECTION("Edge between 2 nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 300);
		CHECK(g.is_connected("A", "B") == true);
		CHECK(g.is_connected("B", "A") == false);
	}

	SECTION("Multiple edges between 2 nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 300);
		g.insert_edge("A", "B", 500);
		g.insert_edge("A", "B", 900);
		CHECK(g.is_connected("A", "B") == true);
		CHECK(g.is_connected("B", "A") == false);
	}
}