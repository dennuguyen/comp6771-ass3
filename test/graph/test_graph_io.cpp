// Author: Dan Nguyen
// Last Modified Date: 2021/08/02
//
// This test file contains test cases for the operator<< function of gdwg::graph.

#include "gdwg/graph.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Output stream should return correct stream") {
	SECTION("Empty graph") {}
	SECTION("Single-directed graph") {}
	SECTION("Cyclic graph") {}
	SECTION("Tree graph") {}
	SECTION("Forest graph") {}
}
