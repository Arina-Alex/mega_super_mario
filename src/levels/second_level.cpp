#include "second_level.hpp"

using biv::SecondLevel;

SecondLevel::SecondLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool SecondLevel::is_final() const noexcept {
	return true;
}

biv::GameLevel* SecondLevel::get_next() {
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void SecondLevel::init_data() {

	ui_factory->create_box({16, 25}, 10, 3); 
	ui_factory->create_mario({22, 10}, 3, 3);
	ui_factory->create_mushroom_box({17, 16}, 3, 3);

	ui_factory->create_moving_platform({42, 25}, 4, 1, 0.15, 15);

	ui_factory->create_box({38, 15}, 4, 1); 
	ui_factory->create_jumping_enemy({38, 12}, 3, 2); 

	ui_factory->create_flying_enemy({50, 17}, 3, 2, 0.4, 3);
	ui_factory->create_flying_enemy({50, 22}, 3, 2, 0.4, 3);

	ui_factory->create_box({70, 25}, 10, 3);
	ui_factory->create_ship({72, 20}, 10, 5);


}
