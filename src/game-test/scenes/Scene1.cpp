#include "Scene1.h"
#include "../../engine/debug/Debug.h"
#include "../../engine/camera/FreeCamera.h"

void Scene1::handleInputEvent(const InputEvent & event, const InputHandlerCode & code)
{
	defaultInputEventHandle(event);
	defaultCameraInputHandler(event, code);
	if (event.type == InputEventType::KEY_DOWN)
	{
		switch (event.key)
		{
		case (KeyCode::F4):
		{
			if (event.ctrlDown)
			{
				registerEngineEvent(std::make_shared<engine::ShutdownEvent>());
			}
			break;
		}
		case (KeyCode::NUM1):
		{
			registerEngineEvent(std::make_shared<engine::ChangeBackgroundEvent>(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)));
			break;
		}
		case (KeyCode::NUM2):
		{
			registerEngineEvent(std::make_shared<engine::ChangeBackgroundEvent>(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)));
			break;
		}
		case (KeyCode::NUM3):
		{
			registerEngineEvent(std::make_shared<engine::ChangeBackgroundEvent>(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f)));
			break;
		}
		case (KeyCode::NUM4):
		{
			registerEngineEvent(std::make_shared<engine::ChangeBackgroundEvent>(glm::vec4(1.0f, 1.0f, 0.0f, 0.5f)));
			break;
		}
		case (KeyCode::NUM5):
		{
			registerEngineEvent(std::make_shared<engine::ChangeBackgroundEvent>(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)));
			break;
		}
		case (KeyCode::F5):
		{
			if (event.ctrlDown)
			{
				registerDelayedEngineEvent(std::make_shared<engine::DelayedShutdownEvent>(5.0));
			}
			break;
		}
		case (KeyCode::NUM6):
		{
			registerDelayedEngineEvent(std::make_shared<engine::DelayedChangeBackgroundEvent>(5.0, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)));
			break;
		}
		case (KeyCode::NUM0):
		{
			if (event.ctrlDown)
			{
				registerEngineEvent(std::make_shared<engine::ChangeMaterialEvent>("test", "simpleDiffuseRed"));
			}
			else
			{
				registerEngineEvent(std::make_shared<engine::ChangeMaterialEvent>("test", "simpleDiffuseBlue"));
			}
			break;
		}
		case (KeyCode::NUM8):
		{
			registerDelayedEngineEvent(std::make_shared<engine::DelayedChangeMaterialEvent>(2.0, "test", "simplePositionMaterial"));
			break;
		}
		case (KeyCode::NUM9):
		{
			registerEngineEvent(std::make_shared<engine::ChangeMaterialEvent>("test", "simplePositionMaterial"));
			break;
		}
		case (KeyCode::W):
		{
			//manager->entityMap.getItem("test")->translateEntity(glm::vec3(0.0f, Clock::deltaTime * 5.0f, 0.0f));
			break;
		}
		case (KeyCode::P):
		{
			manager->cameraManager.activateCamera("presCam");
			break;
		}
		case (KeyCode::O):
		{
			manager->cameraManager.activateCamera("orthoCam");
			break;
		}
		case (KeyCode::K):
		{
			manager->cameraManager.activateCamera("orthoCam2D");
			break;
		}
		case(KeyCode::L):
		{
			manager->cameraManager.activateCamera("FPSCam");
			break;
		}
		case(KeyCode::M):
		{
			manager->cameraManager.activateCamera("targetCam");
			break;
		}
		case(KeyCode::N):
		{
			manager->cameraManager.activateCamera("arcBallCam");
			break;
		}
		case(KeyCode::Z):
		{
			manager->entityMap.getItem("test")->getModel()->setMaterial(manager->materialMap.getItem("simpleVertexADSRed"));
			break;
		}
		case(KeyCode::X):
		{
			manager->entityMap.getItem("test")->getModel()->setMaterial(manager->materialMap.getItem("simpleFragmentADSRed"));
			break;
		}
		case(KeyCode::C):
		{
			manager->entityMap.getItem("test")->getModel()->setMesh(manager->meshMap.getItem("sphere32"));
			break;
		}
		case(KeyCode::V):
		{
			manager->entityMap.getItem("test")->getModel()->setMesh(manager->meshMap.getItem("sphere32_2"));
			break;
		}
		case(KeyCode::B):
		{
			manager->entityMap.getItem("test")->getModel()->setMesh(manager->meshMap.getItem("torus24"));
			break;
		}
		}
	}
	else if (event.type == InputEventType::KEY_UP)
	{
		switch (event.key)
		{
		case (KeyCode::NUM8):
		{
			registerDelayedEngineEvent(std::make_shared<engine::DelayedChangeMaterialEvent>(2.0, "test", "simpleColorMaterial"));
			break;
		}
		case(KeyCode::NUM9):
		{
			registerEngineEvent(std::make_shared<engine::ChangeMaterialEvent>("test", "simpleColorMaterial"));
			break;
		}
		}
	}
}

void Scene1::update()
{
	handleInputKeys();
}

void Scene1::handleInputKeys()
{
	Scene::handleInputKeys();
	if (inputData.keys[static_cast<int>(KeyCode::W)] == true)
	{
		std::shared_ptr<FreeCamera> cam = std::static_pointer_cast<FreeCamera>(manager->cameraManager.getCamera("presCam"));
		cam->moveForward(5.0f * Clock::deltaTime);
	}
	if (inputData.keys[static_cast<int>(KeyCode::S)] == true)
	{
		std::shared_ptr<FreeCamera> cam = std::static_pointer_cast<FreeCamera>(manager->cameraManager.getCamera("presCam"));
		cam->moveForward(-5.0f * Clock::deltaTime);
	}
	if (inputData.keys[static_cast<int>(KeyCode::A)] == true)
	{
		std::shared_ptr<FreeCamera> cam = std::static_pointer_cast<FreeCamera>(manager->cameraManager.getCamera("presCam"));
		cam->moveRight(5.0f * Clock::deltaTime);
	}
	if (inputData.keys[static_cast<int>(KeyCode::D)] == true)
	{
		std::shared_ptr<FreeCamera> cam = std::static_pointer_cast<FreeCamera>(manager->cameraManager.getCamera("presCam"));
		cam->moveRight(-5.0f * Clock::deltaTime);
	}

	if (inputData.keys[static_cast<int>(KeyCode::Q)] == true)
	{
		std::shared_ptr<FreeCamera> cam = std::static_pointer_cast<FreeCamera>(manager->cameraManager.getCamera("presCam"));
		cam->moveUp(-5.0f * Clock::deltaTime);
	}
	if (inputData.keys[static_cast<int>(KeyCode::E)] == true)
	{
		std::shared_ptr<FreeCamera> cam = std::static_pointer_cast<FreeCamera>(manager->cameraManager.getCamera("presCam"));
		cam->moveUp(5.0f * Clock::deltaTime);
	}
}
