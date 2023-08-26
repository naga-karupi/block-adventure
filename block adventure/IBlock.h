#pragma once

class IBlock {
	inline static Array<String> block_list{};
	size_t block_number;

public:
	static constexpr Size block_size{100, 100};

	String block_name;
	bool destroyable;

	IBlock(String , bool);
	[[nodiscard]]
	constexpr bool operator == (IBlock&) const noexcept;

	[[nodiscard]]
	constexpr size_t GetBlockNumber() const noexcept{
		return block_number;
	}

	virtual bool Collide() = 0;
	virtual void TouchEvent() = 0;
	virtual void DestroyEvent() = 0;
	virtual void BlockDraw() = 0;

	IBlock() = delete;
};
