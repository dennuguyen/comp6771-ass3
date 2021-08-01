#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Erasing node should remove node from graph") {
	SECTION("Graph with 1 node") {
		auto g = gdwg::graph<std::string, int>({"node A"});
		REQUIRE(g.empty() == false);
		g.erase_node("node A");
		CHECK(g.empty() == true);
	}

	SECTION("Graph with some nodes") {
		auto g = gdwg::graph<std::string, int>({"node A", "node B", "node C", "node D"});
		REQUIRE(g.empty() == false);
		g.erase_node("node A");
		g.erase_node("node B");
		g.erase_node("node C");
		g.erase_node("node D");
		CHECK(g.empty() == true);
	}
}

TEST_CASE("Erasing non-existent node should do nothing") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<std::string, int>();
		REQUIRE(g.empty() == true);
		g.erase_node("");
		CHECK(g.empty() == true);
	}

	SECTION("Graph without specified node") {
		auto g = gdwg::graph<std::string, int>({"node A", "node B", "node C", "node D"});
		REQUIRE(g.nodes().size() == 4);
		g.erase_node("node E");
		CHECK(g.nodes().size() == 4);
	}
}

TEST_CASE("Erasing node should remove all outgoing edges from that node") {}

TEST_CASE("Erasing node should remove all incoming edges to that node") {}

TEST_CASE("Successfully erasing a node should return true") {
	SECTION("Graph with 1 node") {
		auto g = gdwg::graph<std::string, int>({"node A"});
		CHECK(g.erase_node("node A") == true);
	}

	SECTION("Graph with some nodes") {
		auto g = gdwg::graph<std::string, int>({"node A", "node B", "node C", "node D"});
		CHECK(g.erase_node("node A") == true);
		CHECK(g.erase_node("node B") == true);
		CHECK(g.erase_node("node C") == true);
		CHECK(g.erase_node("node D") == true);
	}
}

TEST_CASE("Unsuccessfully erasing a node should return false") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<std::string, int>();
		CHECK(g.erase_node("") == false);
	}

	SECTION("Graph without specified node") {
		auto g = gdwg::graph<std::string, int>({"node A", "node B", "node C", "node D"});
		CHECK(g.erase_node("node E") == false);
	}
}

TEST_CASE("Erasing a node should work on various data types") {
	SECTION("Nodes with integer data type") {
		auto g = gdwg::graph<int, int>({0});
		REQUIRE(g.empty() == false);
		g.erase_node(0);
		CHECK(g.empty() == true);
	}

	SECTION("Nodes with doubles data type") {
		auto g = gdwg::graph<double, int>({5.2438});
		REQUIRE(g.empty() == false);
		CHECK(g.erase_node(5.2438) == true);
		CHECK(g.empty() == true);
	}

	SECTION("Nodes with char data type") {
		auto g = gdwg::graph<char, int>({'c'});
		REQUIRE(g.empty() == false);
		CHECK(g.erase_node('c') == true);
		CHECK(g.empty() == true);
	}

	SECTION("Nodes with string data type") {
		auto g = gdwg::graph<std::string, int>({"kjawfnlk3j22u12jouijne11"});
		REQUIRE(g.empty() == false);
		g.erase_node("kjawfnlk3j22u12jouijne11");
		CHECK(g.empty() == true);
	}
}