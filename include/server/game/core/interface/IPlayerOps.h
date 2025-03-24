#ifndef IPLAYEROPS_H
#define IPLAYEROPS_H

class IPlayerOps {
public:
	virtual ~IPlayerOps() = default;

	virtual Player& getPlayer(const boost::uuids::uuid) = 0;
	


	virtual void updateStatus(TeamType team) = 0;
};

#endif