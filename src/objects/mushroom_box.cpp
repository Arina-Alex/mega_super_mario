#include "mushroom_box.hpp"

using biv::MushroomBox;

MushroomBox::MushroomBox(
	const Coord& top_left, 
	const int width, const int height,
	UIFactory* ui_factory
) : Box(top_left, width, height), ui_factory(ui_factory) {}

biv::Rect MushroomBox::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed MushroomBox::get_speed() const noexcept {
	return {0, 0};
}

void MushroomBox::process_horizontal_static_collision(Rect* obj) noexcept {}

void MushroomBox::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v < 0) {
		kill();
		ui_factory->create_mushroom({top_left.x, top_left.y - 3}, 3, 2);
	}
}

void MushroomBox::process_vertical_static_collision(Rect* obj) noexcept {}
