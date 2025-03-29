#ifndef IBOARDMEDI_H
#define IBOARDMEDI_H

// ***************************************************************************/

class IBoardMedi {
public:
	virtual ~IBoardMedi() = default;

	virtual bool isOccupyingAll(TeamType team) = 0;
	virtual bool isOccupyingEnough(TeamType team) = 0;
	virtual bool isOccupyingFewer(TeamType team) = 0;
};

#endif