#pragma once

class IBlock {

public:
	virtual void TouchedEvent() = 0;
	virtual void RideEvent() = 0;
	virtual void DestroyEvent() = 0;

	virtual void BlockDraw() const = 0;
};

