#ifndef _GAME_H_
#define _GAME_H_

#include "io_utils.h"
#include "pacman.h"
#include "ghost.h"
#include "map.h"
#include "fruit.h"

struct Game_State {
	short int lives = 3;
	short int score = 0;
};

class Game {
private:
	Map				map;
	Pacman	        pacman = { {1,1}, Color::YELLOW };
	vector<Ghost>	ghost;
	Fruit			fruit;
	Position		legend;
	Difficulty		difficulty;
	int				lives = DEFAULT_NUM_OF_LIVES;
	int				score = 0;

	bool isObjEatenByGhosts(const Game_Object& obj) const;
	void printMessage(const char* message);
	void addPointToScore() { score++; };
	void decreaseLives() { lives--; };
	void handleIsEaten(bool& game_over, stack<Position> stacks[4]);

	void updateBreadcrumbs();
	void handlePlayerInput();
	void pacmanEatenEvent();
	void printParameters() const;

	void moveGhosts(int& counter, stack<Position> stack[4]);
	void countdown();
	void pause();

	static Game instance;
public:
	Game(Pacman pacman, vector<Ghost> ghosts, Map map, Position legend, Game_State state, Difficulty difficulty) :
		pacman(pacman), ghost(ghosts), map(map), fruit(map), legend(legend), lives(state.lives), score(state.score), difficulty(difficulty) {};

	Game_State start();
};

#endif
