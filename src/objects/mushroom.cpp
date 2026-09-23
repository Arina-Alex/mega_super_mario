#include "mushroom.hpp"
#include "mario.hpp"


using biv::Mushroom;

Mushroom::Mushroom(const Coord& top_left, const int width, const int height) 
	: RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0;
	hspeed = 0.2;
}

biv::Rect Mushroom::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed Mushroom::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void Mushroom::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void Mushroom::process_mario_collision(Collisionable* mario_col) noexcept {
	mario_col->process_mushroom_collision(this);
    kill();
}

void Mushroom::process_vertical_static_collision(Rect* obj) noexcept {
    if (vspeed > 0) {
        top_left.y -= vspeed;
        vspeed = 0;
    }
}