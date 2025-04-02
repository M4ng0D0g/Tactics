#ifndef ICLIENTDATA_H
#define ICLIENTDATA_H

#include <enet/enet.h>

// ***************************************************************************/

class IClientData {
public:
	virtual ~IClientData() = default;

	virtual bool findPlayer(const enet_uint8&) = 0;
	virtual bool getPlayer(const enet_uint8&) = 0;
};

#endif