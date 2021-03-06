/* This program is free software. It comes without any warranty, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://www.wtfpl.net/ for more details. */

#ifndef GAMESETTINGS_HPP
#define GAMESETTINGS_HPP

#include <string>
#include <map>
#include <sstream>

class GameSettings
{
public:
	void LoadConfig(const std::string& inFilename);
	void SaveConfig(const std::string& inFilename);

	std::string GetSettingString(const std::string& key);
	int GetSettingInt(const std::string& key);
	float GetSettingFloat(const std::string& key);

	static GameSettings* const GetInstance()
	{
		if (instance == nullptr)
			instance = new GameSettings();
		return instance;
	}

private:
	GameSettings();

	static GameSettings* instance;

	std::map<std::string, std::string> configMap;
};

#endif