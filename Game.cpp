#include "Game.h"
//SDL_Texture* m_pTexture;
//SDL_Rect m_sourceRectangle;
//SDL_Rect m_destinationRectangle;

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
                SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
            }
            else { return false; }//랜더러 생성 실패
        }
        else { return false; }//윈도우 생성 실패
    }
    else { return false; }//SDL 초기화 실패
    
    if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
    {
        return false;
    }

    m_currentFrame = 0;
    m_bRunning = true;
    return true;
}

void Game::Render()
{
    SDL_RenderClear(m_pRenderer);
    TheTextureManager::Instance()->draw("image", 0, 0, 128, 82, m_pRenderer);
    TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame,m_pRenderer);
    SDL_RenderPresent(m_pRenderer);
}

bool Game::Running()
{
    return m_bRunning;
}

void Game::Update()
{
    m_currentFrame = (SDL_GetTicks() / 100) % 6;
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
