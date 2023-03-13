#include "PlayScene.h"
#include "Game.h"
#include "EventManager.h"
#include <Windows.h>

// required for IMGUI
#include "imgui.h"
#include "imgui_sdl.h"
#include "Renderer.h"
#include "Util.h"

PlayScene::PlayScene()
{
	PlayScene::Start();
}

PlayScene::~PlayScene()
= default;

void PlayScene::Draw()
{
	DrawDisplayList();

	SDL_SetRenderDrawColor(Renderer::Instance().GetRenderer(), 255, 255, 255, 255);
}

void PlayScene::Update()
{
	UpdateDisplayList();
}

void PlayScene::Clean()
{
	RemoveAllChildren();
}

void PlayScene::HandleEvents()
{
	EventManager::Instance().Update();

	if (EventManager::Instance().IsKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance().Quit();
	}

	if (EventManager::Instance().IsKeyDown(SDL_SCANCODE_1))
	{
		Game::Instance().ChangeSceneState(SceneState::START);
	}

	if (EventManager::Instance().IsKeyDown(SDL_SCANCODE_2))
	{
		Game::Instance().ChangeSceneState(SceneState::END);
	}
}



void PlayScene::Start()
{
	// Set GUI Title
	m_guiTitle = "Play Scene";


	//m_buildObstacles();


	//game objescts
	m_pStarShip = new StarShip();
	m_pStarShip->GetTransform()->position = glm::vec2(150.0f, 300.0f);
	AddChild(m_pStarShip);

	m_pTarget = new Target();
	m_pTarget->GetTransform()->position = glm::vec2(600.0f, 300.0f);
	AddChild(m_pTarget);


	//m_buildGrid();
	//auto offset = glm::vec2(Config::TILE_SIZE * 0.5f, Config::TILE_SIZE * 0.5f);

	//m_findShortestPath();
	// Add the StarShip to the Scene
	//m_addObjectToGrid(m_pStarShip, 1, 3, TileStatus::START);

	// Add the Target to the Scene
	//m_addObjectToGrid(m_pTarget, 15, 11, TileStatus::GOAL);

	

	//m_markImpassable();

	// Preload Sounds

	SoundManager::Instance().Load("../Assets/Audio/yay.ogg", "yay", SoundType::SOUND_SFX);
	SoundManager::Instance().Load("../Assets/Audio/thunder.ogg", "thunder", SoundType::SOUND_SFX);

	//m_computeTileCosts();

	ImGuiWindowFrame::Instance().SetGuiFunction(std::bind(&PlayScene::GUI_Function, this));
}

void PlayScene::GUI_Function()
{
	//auto offset = glm::vec2(Config::TILE_SIZE * 0.5f, Config::TILE_SIZE * 0.5f);

	// Always open with a NewFrame
	ImGui::NewFrame();

	// See examples by uncommenting the following - also look at imgui_demo.cpp in the IMGUI filter
	//ImGui::ShowDemoWindow();
	
	ImGui::Begin("GAME3001 - W2023 - Lab6.1", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_MenuBar );

	ImGui::Separator();

	// Debug Properties
	//static bool toggle_grid = false;
	if(ImGui::Checkbox("Toggle Grid", &m_isGridEnabled))
	{
		//m_isGridEnabled = toggle_grid;
		//m_setGridEnabled(m_isGridEnabled);
	}

	//ImGui::Separator();


	







	ImGui::Separator();

	

	ImGui::Separator();


	
	ImGui::Separator();

	//position variable
	static int start_position[] = {
	static_cast<int>(m_pStarShip->GetTransform()->position.x),
	static_cast<int>(m_pStarShip->GetTransform()->position.y) };

	static int goal_position[] = {
	static_cast<int>(m_pTarget->GetTransform()->position.x),
	static_cast<int>(m_pTarget->GetTransform()->position.y) };


	


	ImGui::Separator();



	// StarShip Properties

	if(ImGui::SliderInt2("starship Position", start_position, 0, 800))
	{
		// constrain the object within max rows
	
		m_pStarShip->GetTransform()->position.x = start_position[0];
		m_pStarShip->GetTransform()->position.y = start_position[1];


		//m_moveGameObject(m_pTarget, start_position[0], start_position[1], TileStatus::GOAL);


	}

	ImGui::Separator();

	// Target Properties

	if (ImGui::SliderInt2("target Position", goal_position, 0, 800))
	{
		// constrain the object within max rows
		
		m_pTarget->GetTransform()->position.x = goal_position[0];
		m_pTarget->GetTransform()->position.y = goal_position[1];
	}

	ImGui::End();
}

void PlayScene::m_buildGrid()
{
	const auto tile_size = Config::TILE_SIZE;

	// layout a grid of tiles
	for (int row = 0; row < Config::ROW_NUM; ++row)
	{
		for (int col = 0; col < Config::COL_NUM; ++col)
		{

		}
	}
}




void PlayScene::m_buildObstacles() {

	for (int i = 0; i < 300; ++i) {
		m_pObstacles.push_back(new Obstacle());
	}


}


