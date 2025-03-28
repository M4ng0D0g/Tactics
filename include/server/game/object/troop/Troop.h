#ifndef TROOP_H
#define TROOP_H

#include "interface/ICommandProcessor.h"
#include "game/enums/TeamEnum.h"
#include "game/enums/TroopEnum.h"
#include "interface/ITroopAction.h"

#include <utility>
#include <memory>

// ***************************************************************************/

class Troop : public std::enable_shared_from_this<Troop> {
private:
	std::shared_ptr<ICommandProcessor> _processor;

	TroopEnum::Type _type;
	TeamEnum::Type _team;
	std::pair<int, int> _loc;
	int _defaultHp;
	int _defaultAtk;
	int _hp;
	int _atk;
	
	std::unordered_map<TroopEnum::Action, std::shared_ptr<ITroopAction>> _actions;

public:
	Troop() = default;
	Troop(TroopEnum::Type, TeamEnum::Type, int defaultHp, int defaultAtk, std::shared_ptr<ICommandProcessor>);

	//Getter
	std::shared_ptr<Troop> getShared();
	TeamEnum::Type getTeam() const;
	TroopEnum::Type getType() const;
	std::pair<int, int> getLocation() const;
	int getDefaultHp() const;
	int getDefaultAtk() const;
	int getHp() const;
	int getAtk() const;

	//Setter
	void setLocation(std::pair<int, int> loc);
	void setAction(TroopEnum::Action actionEnum, std::shared_ptr<ITroopAction> action);
	void setDefaultHp(int hp);
	void setDefaultAtk(int atk);
	void setHp(int hp);
	void setAtk(int atk);

	//Perform
	void performAction(TroopEnum::Action action);
};

#endif // TROOP_H
