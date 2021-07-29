#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Copy assignment should copy graph with same values as original") {
	SECTION("Copy assign empty graph") {}
	SECTION("Copy assign graph with only nodes") {}
	SECTION("Copy assign graph with nodes and edges") {}
	SECTION("Copy assign graph with cycle") {}
	SECTION("Copy assign graph with tree") {}
}

TEST_CASE("Copy assignment should not modify original") {
	SECTION("Copy assign empty graph") {}
	SECTION("Copy assign graph with only nodes") {}
	SECTION("Copy assign graph with nodes and edges") {}
	SECTION("Copy assign graph with cycle") {}
	SECTION("Copy assign graph with tree") {}
}

TEST_CASE("Move assignment should create graph with the values of the original") {
	SECTION("Move assign empty graph") {}
	SECTION("Move assign graph with only nodes") {}
	SECTION("Move assign graph with nodes and edges") {}
	SECTION("Move assign graph with cycle") {}
	SECTION("Move assign graph with tree") {}
}