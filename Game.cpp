/*
* 진행도
*   <2주차:HelloSDL ~ 7주차: 상속, 다형성>
* 실습 이외의 변경 사항
*   GameObject.cpp 업데이트 내용 삭제
*       GameObject는 부모 클래스이고 자식 클래스는 상속받아서 오버라이딩 쓰기 때문에 내용이 필요없다 판단해서 삭제함.
*   Player.cpp 업데이트 함수 수정
*       이제 플레이어가 화면 밖으로 나가지 않습니다.
*       플레이어에게 애니메이션을 적용했습니다.
*       플레이어가 방향을 전환하면 애니메이션도 전환됩니다.
*   Player.h Load()함수와 Draw()함수 제거
*       부모의 기능을 똑같이 받아 쓰기 때문에 재정의를 하지 않음.
*/
#include "Game.h"
#include "TextureManager.h"

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

    GameObject* m_go = new GameObject(); //아무 기능 없는 오브젝트
    GameObject* m_player = new Player();

    m_go->Load(100, 100, 128, 82, "animate");
    m_player->Load(300, 300, 128, 82, "animate");
    m_gameObjects.push_back(m_go);
    m_gameObjects.push_back(m_player);
    m_bRunning = true;
    return true;
}

void Game::Render()
{
    SDL_RenderClear(m_pRenderer);
    for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->Draw(m_pRenderer);
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
