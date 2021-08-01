#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Inserting a unique node should create a node in the graph") {
	SECTION("Inserting into an empty graph") {
		auto g = gdwg::graph<std::string, int>();
		g.insert_node("new node");
		CHECK(g.is_node("new node") == true);
	}

	SECTION("Inserting into a graph with nodes") {
		auto g = gdwg::graph<std::string, int>({"a", "b", "c"});
		g.insert_node("new node");
		CHECK(g.is_node("new node") == true);
	}
}

TEST_CASE("Inserting a non-unique node should not create a node in the graph") {
	SECTION("Inserting into a graph with a node") {
		auto g = gdwg::graph<std::string, int>({"new node"});
		REQUIRE(g.nodes().size() == 1);
		g.insert_node("new node");
		CHECK(g.nodes().size() == 1);
	}

	SECTION("Inserting into a graph with some nodes") {
		auto g = gdwg::graph<std::string, int>({"a", "b", "c"});
		REQUIRE(g.nodes().size() == 3);
		g.insert_node("a");
		g.insert_node("b");
		g.insert_node("c");
		CHECK(g.nodes().size() == 3);
	}
}

TEST_CASE("Successfully inserting a node should return true") {
	SECTION("Inserting into an empty graph") {
		auto g = gdwg::graph<std::string, int>();
		CHECK(g.insert_node("new node") == true);
	}

	SECTION("Inserting into a graph with nodes") {
		auto g = gdwg::graph<std::string, int>({"a", "b", "c"});
		CHECK(g.insert_node("new node") == true);
	}
}

TEST_CASE("Unsuccessfully inserting a node should return false") {
	SECTION("Inserting into a graph with a node") {
		auto g = gdwg::graph<std::string, int>({"new node"});
		CHECK(g.insert_node("new node") == false);
	}

	SECTION("Inserting into a graph with some nodes") {
		auto g = gdwg::graph<std::string, int>({"a", "b", "c"});
		CHECK(g.insert_node("a") == false);
		CHECK(g.insert_node("b") == false);
		CHECK(g.insert_node("c") == false);
	}
}

TEST_CASE("Inserting a node should work on various data types") {
	SECTION("Nodes with integer data type") {
		auto g = gdwg::graph<int, int>();
		REQUIRE(g.empty() == true);
		g.insert_node(1);
		CHECK(g.empty() == false);
	}

	SECTION("Nodes with doubles data type") {
		auto g = gdwg::graph<double, int>();
		REQUIRE(g.empty() == true);
		g.insert_node(5.2438);
		CHECK(g.empty() == false);
	}

	SECTION("Nodes with char data type") {
		auto g = gdwg::graph<char, int>();
		REQUIRE(g.empty() == true);
		g.insert_node('c');
		CHECK(g.empty() == false);
	}

	SECTION("Nodes with string data type") {
		auto g = gdwg::graph<std::string, int>();
		REQUIRE(g.empty() == true);
		g.insert_node("kjawfnlk3j22u12jouijne11");
		CHECK(g.empty() == false);
	}
}