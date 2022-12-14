#pragma once
#include "../models/game_state.h"
#include "../models/player.h"
#include "../models/card.h"
#include "../view/text_view.h"
#include <iostream>
#include <istream>
#include <map>
#include "command.h"

class Controller {
public:
	virtual void startGame() = 0;
};


class TextController : Controller {
	GameState& _model;
	TextView& _view;
	std::istream& _input;
	bool _quit = false;


	std::map<std::string, TextCommand*> make_dict() {
		std::map<std::string, TextCommand*> m;
		m["play"] = &PlayCommand();
		m["draw"] = &DrawCommand();
		m["uno"] = &UnoCommand();
		return m;
	}

	const std::map<std::string, TextCommand*> _command_dict = make_dict();

	const void playerDoTurn(Player& player);


	

public:
	TextController(GameState& model, TextView& view, std::istream& istream) : _model(model), _view(view), _input(istream) {};

	void startGame();
};
