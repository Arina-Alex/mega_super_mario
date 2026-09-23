#include "console_flying_enemy.hpp"

using biv::ConsoleFlyingEnemy;

ConsoleFlyingEnemy::ConsoleFlyingEnemy(const Coord& top_left, const int width, const int height, float speed, float max_dist) 
	: FlyingEnemy(top_left, width, height, speed, max_dist) {}

char ConsoleFlyingEnemy::get_brush() const noexcept {
	return '^';
}
