#include "flying_enemy.hpp"

#include "map_movable.hpp"

using biv::FlyingEnemy;

FlyingEnemy::FlyingEnemy(const Coord& top_left, const int width, const int height, float speed, float max_dist) 
	: RectMapMovableAdapter(top_left, width, height) {
	this->start_x = top_left.x;
    this->max_dist = max_dist;
	vspeed = 0;
	hspeed = speed;
}

biv::Rect FlyingEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed FlyingEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void FlyingEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void FlyingEnemy::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
		kill();
	} else {
		mario->kill();
	}
}

void FlyingEnemy::process_vertical_static_collision(Rect* obj) noexcept {}

void FlyingEnemy::move_vertically() noexcept {}

void FlyingEnemy::move_horizontally() noexcept {
    top_left.x += hspeed;
    if (top_left.x >= start_x + max_dist || top_left.x <= start_x - max_dist) {
        hspeed = -hspeed;
    }
}

void FlyingEnemy::move_map_left() noexcept {
    RectMapMovableAdapter::move_map_left();
    start_x -= biv::MapMovable::MAP_STEP;
}

void FlyingEnemy::move_map_right() noexcept {
    RectMapMovableAdapter::move_map_right();
    start_x += biv::MapMovable::MAP_STEP;
}