/*
*진행도
*   <2주차:HelloSDL ~ 9주차 Vector2D>
* 실습 이외의 변경 사항
*   백터를 사용하기 때문에 m_x, m_y에 대한 내용을 다 없앰.
*   부모인 SDLGameObject의 Update()를 사용하기 위해서 자식의 Update()를 재정의 하지 않음.
*   애니메이션 적용
*/
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "TextureManager.h"

Game* Game::s_pInstance = 0;
Game::~Game()
{
}
Game* Game::Instance()
{
    if (s_pInstance == 0)
    {
        s_pInstance = new Game();
        return s_pInstance;
    }
    return s_pInstance;
}
bool Game::Init(const char* title, int xpos, int ypos, int width, int height, int flags)
{

    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0)
        {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if (m_pRenderer != 0)
            {
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
            }
            else { return false; }//랜더러 생성 실패
        }
        else { return false; }//윈도우 생성 실패
    }
    else { return false; }//SDL 초기화 실패
    if(!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
    {
        return false;
    }
    m_gameObjects.push_back(new Player(new LoaderParams(200, 100, 128, 82, "animate")));
    m_gameObjects.push_back(new Enemy(new LoaderParams(100, 100, 128, 82, "animate")));

    m_bRunning = true;
    return true;
}

void Game::Render()
{
    SDL_RenderClear(m_pRenderer);
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->Draw();
    }
    SDL_RenderPresent(m_pRenderer);
}

bool Game::Running()
{
    return m_bRunning;
}

void Game::Update()
{
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->Update();
    }
}

void Game::HandleEvents()
{
    SDL_Event event;//이벤트
    while (SDL_PollEvent(&event))//이벤트 전달
    {
        switch (event.type)//이벤트 타입, X를 누르면 루프문을 벗어난다.
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        
        default:
            break;
        }
    }
}

void Game::Clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

SDL_Renderer* Game::getRenderer() const
{
    return m_pRenderer;
}

