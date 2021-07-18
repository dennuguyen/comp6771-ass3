#ifndef GDWG_GRAPH_HPP
#define GDWG_GRAPH_HPP

template<typename NodeType, typename EdgeType>
namespace gdwg {
	class graph {
	public:
		// gdwg.iterator
		class iterator {
			public:
			using value_type = graph<N, E>::value_type;
			using reference = value_type;
			using pointer = void;
			using difference_type = std::ptrdiff_t;
			using iterator_category = std::bidirectional_iterator_tag;

			// gdwg.iterator.ctor
			iterator() = default;
			explicit iterator(unspecified);

			// gdwg.iterator.source
			auto operator*() -> reference;

			// gdwg.iterator.traversal
			auto operator++() -> iterator&;
			auto operator++(int) -> iterator;
			auto operator--() -> iterator&;
			auto operator--(int) -> iterator;

			// gdwg.iterator.comparison
			auto operator==(iterator const&) -> bool;
			private:
			explicit iterator(unspecified);
		};

		// gdwg.ctor
		graph();
		graph(std::initializer_list<NodeType>);
		graph(NodeType, NodeType);
		graph(graph const&);
		graph(graph&&) noexcept;
		auto operator=(graph&&) noexcept -> graph&;
		auto operator=(graph const&) -> graph&;

		// gdwg.modifiers
		auto insert_node(NodeType const&) -> bool;
		auto insert_edge(NodeType const&, NodeType const&, EdgeType const&) -> bool;
		auto replace_node(NodeType const&, NodeType const&) -> bool;
		auto merge_replace_node(NodeType const&, NodeType const&) -> void;
		auto erase_node(NodeType const&) -> bool;
		auto erase_edge(NodeType const&, NodeType const&, EdgeType const&) -> bool;
		auto erase_edge(iterator) -> iterator;
		auto erase_edge(iterator, iterator) -> iterator;
		auto clear() noexcept -> void;

		// gdwg.accessors
		[[nodiscard]] auto is_node(Nodetype const&) -> bool;
		[[nodiscard]] auto empty() -> bool;
		[[nodiscard]] auto is_connected(NodeType const& , NodeType const& ) -> bool;
		[[nodiscard]] auto nodes() -> std::vector<NodeType>;
		[[nodiscard]] auto weights(NodeType const&, NodeType const& ) -> std::vector<E>;
		[[nodiscard]] auto find(NodeType const&, NodeType const&, EdgeType const&) -> iterator;
		[[nodiscard]] auto connections(NodeType const&) -> std::vector<N>;

		// gdwg.iterator.access
		[[nodiscard]] auto begin() const -> iterator;
		[[nodiscard]] auto end() const -> iterator;

		// gdwg.cmp
		[[nodiscard]] auto operator==(graph const&) -> bool;

		// gdwg.io
		friend auto operator<<(std::ostream& os, graph const& g) -> std::ostream& {}

	private:
		// gdwg.internal
	};
} // namespace gdwg

#endif // GDWG_GRAPH_HPP
