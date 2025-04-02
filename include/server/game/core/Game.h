#ifndef GAME_H
#define GAME_H

#include "GameConfig.h"
#include "GameData.h"
#include "TurnController.h"
#include "interface/IGameMedi.h"
#include <memory>

// ***************************************************************************/

class Game : public std::enable_shared_from_this<Game> {
private:
	GameData _data;
	TurnController _turnController;
	std::weak_ptr<IGameMedi> _mediator;

public:
	/**
	 * @brief 建立 `TurnController` 和 `GameData`，然後向 `GameData` 獲取 `GameMediator` 弱指標。
	 * 
	 * @param config 遊戲設定選項。
	 */
	Game(const GameConfig& config);

	/**
	 * @brief 初始化遊戲資料並開始遊戲。
	 * 
	 * @return void
	 */
	void gameStart();

	/**
	 * @brief 回合開始，將直接從TurnController獲取回合訊息。
	 * 
	 * @return void
	 */
	void turnStart();

	/**
	 * @brief 回合結束，將直接從TurnController獲取回合訊息。
	 * 
	 * @return void
	 */
	void turnEnd();

	/**
	 * @brief 淘汰隊伍，之後回合將會跳過該隊伍。
	 * 
	 * @param eliminatedTeam 被淘汰的隊伍。
	 * 
	 * @return void
	 */
	void teamEliminate(TeamEnum::Type eliminatedTeam);

	/**
	 * @brief 隊伍勝利，此方法不會主動結束遊戲。
	 * 
	 * @param victoryTeam 勝利隊伍。
	 * 
	 * @return void
	 */
	void teamWin(TeamEnum::Type victoryTeam);

	/**
	 * @brief 結束遊戲並清除資料，需要向 `PacketHandler` 解除 `ClientManager` 訂閱。
	 * 
	 * @return void
	 */
	void gameEnd();

	/**
	 * @brief 遊戲主迴圈。
	 * 
	 * @return void
	 */
	void gameLoop();
};

#endif