#include "GameSettings.hpp"

GameSettings* GameSettings::instance = nullptr;

GameSettings::GameSettings()
{

}

void GameSettings::LoadConfig(const std::string& inFilename)
{
	configMap.insert(std::pair<std::string, std::string>("WindowWidth", "800"));
	configMap.insert(std::pair<std::string, std::string>("WindowHeight", "600"));
}

void GameSettings::SaveConfig(const std::string& inFilename)
{

}

std::string GameSettings::GetSettingString(const std::string& key)
{
	auto cfg = configMap.find(key);
	if (cfg == configMap.end())
		throw std::runtime_error("Error: Could not find key specified");
	return cfg->second;
}

int GameSettings::GetSettingInt(const std::string& key)
{
	auto cfg = configMap.find(key);
	if (cfg == configMap.end())
		throw std::runtime_error("Error: Could not find key specified");

	// Convert the string to int. Throws exception on failure.
	return std::stoi(cfg->second);
}

float GameSettings::GetSettingFloat(const std::string& key)
{
	auto cfg = configMap.find(key);
	if (cfg == configMap.end())
		throw std::runtime_error("Error: Could not find key specified");

	// Convert string to float. Throws exception on failure.
	return std::stof(cfg->second);;
}