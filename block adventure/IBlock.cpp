#include "stdafx.h"
#include "IBlock.h"

IBlock::IBlock(String _block_name, bool _destroyable = false)
	: block_name(_block_name), destroyable(_destroyable) {

	bool is_same_name = false;
	for (int i = 0; i < block_list.size(); i++) {
		if (block_name == block_list[i]) {
			block_number = i;
			is_same_name = true;
			break;
		}
	}

	if (not is_same_name) {
		block_number = block_list.size();
		block_list.push_back(block_name);
	}
}

[[nodiscard]]
constexpr bool IBlock::operator==(IBlock& block) const noexcept {
	return this->GetBlockNumber() == block.GetBlockNumber();
}
