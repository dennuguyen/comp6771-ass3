// Author: Dan Nguyen
// Last Modified Date: 2021/08/02
//
// This test file contains test cases for the erase_node function of gdwg::graph.

#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Erasing node should remove node from graph") {
	SECTION("Graph with 1 node") {
		auto g = gdwg::graph<std::string, int>({"A"});
		g.erase_node("A");
		CHECK(g.is_node("A") == false);
	}

	SECTION("Removing some nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C", "D"});
		g.erase_node("A");
		g.erase_node("C");
		CHECK(g.is_node("A") == false);
		CHECK(g.is_node("B") == true);
		CHECK(g.is_node("C") == false);
		CHECK(g.is_node("D") == true);
	}

	SECTION("Removing all nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C", "D"});
		g.erase_node("A");
		g.erase_node("B");
		g.erase_node("C");
		g.erase_node("D");
		CHECK(g.is_node("A") == false);
		CHECK(g.is_node("B") == false);
		CHECK(g.is_node("C") == false);
		CHECK(g.is_node("D") == false);
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
		auto g = gdwg::graph<std::string, int>({"A", "B", "C", "D"});
		REQUIRE(g.nodes().size() == 4);
		g.erase_node("E");
		CHECK(g.nodes().size() == 4);
	}
}

TEST_CASE("Erasing node should remove all incoming/outgoing edges with that node") {
	SECTION("Removing node with incoming edge") {
		auto g = gdwg::graph<std::string, int>({"A", "B"});
		g.insert_edge("A", "B", 1);
		REQUIRE(g.is_connected("A", "B") == true);
		g.erase_node("B");
		CHECK(g.connections("A") == std::vector<std::string>({}));
	}

	SECTION("Removing node with many incoming edges") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C", "D"});
		g.insert_edge("A", "D", 100);
		g.insert_edge("B", "D", 101);
		g.insert_edge("C", "D", 102);
		g.insert_edge("D", "D", 103);
		REQUIRE(g.is_connected("A", "B") == true);
		REQUIRE(g.is_connected("B", "C") == true);
		REQUIRE(g.is_connected("C", "D") == true);
		REQUIRE(g.is_connected("D", "D") == true);
		g.erase_node("D");
		CHECK(g.connections("A") == std::vector<std::string>({}));
		CHECK(g.connections("B") == std::vector<std::string>({}));
		CHECK(g.connections("C") == std::vector<std::string>({}));
	}

	SECTION("Cyclic graph") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C"});
		g.insert_edge("A", "B", 100);
		g.insert_edge("B", "C", 101);
		g.insert_edge("C", "A", 102);
		REQUIRE(g.is_connected("A", "B") == true);
		REQUIRE(g.is_connected("B", "C") == true);
		REQUIRE(g.is_connected("C", "A") == true);
		g.erase_node("B");
		CHECK(g.connections("A") == std::vector<std::string>({}));
	}
}

TEST_CASE("Successfully erasing a node should return true") {
	SECTION("Graph with 1 node") {
		auto g = gdwg::graph<std::string, int>({"A"});
		CHECK(g.erase_node("A") == true);
	}

	SECTION("Graph with some nodes") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C", "D"});
		CHECK(g.erase_node("A") == true);
		CHECK(g.erase_node("B") == true);
		CHECK(g.erase_node("C") == true);
		CHECK(g.erase_node("D") == true);
	}
}

TEST_CASE("Unsuccessfully erasing a node should return false") {
	SECTION("Empty graph") {
		auto g = gdwg::graph<std::string, int>();
		CHECK(g.erase_node("") == false);
	}

	SECTION("Graph without specified node") {
		auto g = gdwg::graph<std::string, int>({"A", "B", "C", "D"});
		CHECK(g.erase_node("E") == false);
	}
}

TEST_CASE("Erasing a node should work on various data types") {
	SECTION("Nodes with integer data type") {
		auto g = gdwg::graph<int, int>({0});
		REQUIRE(g.is_node(0) == true);
		g.erase_node(0);
		CHECK(g.is_node(0) == false);
	}

	SECTION("Nodes with doubles data type") {
		auto g = gdwg::graph<double, int>({5.2438});
		REQUIRE(g.is_node(5.2438) == true);
		CHECK(g.erase_node(5.2438) == true);
		CHECK(g.is_node(5.2438) == false);
	}

	SECTION("Nodes with char data type") {
		auto g = gdwg::graph<char, int>({'c'});
		REQUIRE(g.is_node('c') == true);
		CHECK(g.erase_node('c') == true);
		CHECK(g.is_node('c') == false);
	}

	SECTION("Nodes with string data type") {
		auto g = gdwg::graph<std::string, int>({"kjawfnlk3j22u12jouijne11"});
		REQUIRE(g.is_node("kjawfnlk3j22u12jouijne11") == true);
		g.erase_node("kjawfnlk3j22u12jouijne11");
		CHECK(g.is_node("kjawfnlk3j22u12jouijne11") == false);
	}
}