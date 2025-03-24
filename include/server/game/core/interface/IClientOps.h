#ifndef ICLIENTOPS_H
#define ICLIENTOPS_H

class IClientOps {
public:
	virtual ~IClientOps() = default;

	virtual const boost::uuids::uuid getID(const Player&) = 0;
	
	virtual void lockOperation() = 0;
	virtual void unlockOperation() = 0;
	virtual void clickBoard(const boost::uuids::uuid, std::pair<int, int>) = 0;
	virtual void clickHand(const boost::uuids::uuid, int) = 0;
};

#endif