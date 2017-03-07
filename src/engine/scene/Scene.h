#pragma once
#include <Windows.h>
#include "../userInput/inputEvent/InputEvent.h"
#include "../userInput/inputEvent/InputHandlerCode.h"
#include <vector>
#include "../settings/SceneSettings.h"
#include <queue>
#include "../event/EngineEvent.h"
#include <memory>

class Scene
{
public:
	Scene(const std::string& name) : name(name) {}

	inline void setWindowHandle(const HWND& hwnd);
	inline const HWND& getWindowHandle() const;

	inline const std::string& getName() { return name; }

	virtual void handleInputEvent(const InputEvent& event, const InputHandlerCode& code);

	inline const std::string& getDataFile() { return settings.dataFile; }
	inline void setDataFile(const std::string& path) { settings.dataFile = path; };

	inline void setEngineEventList(std::queue<std::shared_ptr<EngineEvent>>& list) {engineEventList = &list;}

protected:
	std::string name;
	const HWND* hWnd;
	SceneSettings settings;
	std::queue<std::shared_ptr<EngineEvent>>* engineEventList;
};

const HWND& Scene::getWindowHandle() const
{
	return *hWnd;
}
void Scene::setWindowHandle(const HWND& hwnd)
{
	hWnd = &hwnd;
}