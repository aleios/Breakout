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

	bool success = false;
	int value = ConvertString<int>(cfg->second, success);

	if (!success)
		throw std::runtime_error("Error: Key is not of type (int).");

	return value;
}

float GameSettings::GetSettingFloat(const std::string& key)
{
	auto cfg = configMap.find(key);
	if (cfg == configMap.end())
		throw std::runtime_error("Error: Could not find key specified");

	bool success = false;
	float value = ConvertString<float>(cfg->second, success);

	if (!success)
		throw std::runtime_error("Error: Key is not of type (float).");

	return value;
}