#ifndef IBOARDOPS_H
#define IBOARDOPS_H

class IBoardOps {
public:
	virtual ~IBoardOps() = default;

	virtual bool isOccupyingAll(TeamType team) = 0;
	virtual bool isOccupyingEnough(TeamType team) = 0;
	virtual bool isOccupyingFewer(TeamType team) = 0;
};

#endif