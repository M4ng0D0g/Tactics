#ifndef IPLAYERMEDI_H
#define IPLAYERMEDI_H

// ***************************************************************************/

class IPlayerMedi {
public:
	virtual ~IPlayerMedi() = default;

	virtual Player& getPlayer(const boost::uuids::uuid) = 0;
	virtual void updateStatus(TeamType team) = 0;
};

#endif