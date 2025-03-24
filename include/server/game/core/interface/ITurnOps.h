#ifndef ITURNOPS_H
#define ITURNOPS_H

class ITurnOps {
public:
	virtual ~ITurnOps() = default;

	virtual void beforeTurn(TeamType team) = 0;
	virtual void afterTurn(TeamType team) = 0;
};

#endif