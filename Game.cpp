#include "Game.h"
//SDL_Texture* m_pTexture;
//SDL_Rect m_sourceRectangle;
//SDL_Rect m_destinationRectangle;
bool Game::Init(const char* title,int xpos,int ypos,int height, int width, int flags)
{
  
  if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
  {
    m_pWindow=SDL_CreateWindow(title,xpos,ypos,height,width,flags);    
    if(m_pWindow!=0)
    {
      m_pRenderer=SDL_CreateRenderer(m_pWindow,-1,0);
      if(m_pRenderer!=0)
      {
        SDL_SetRenderDrawColor(m_pRenderer,0,0,0,255);
      }
      else {return false;}//랜더러 생성 실패
    }
    else {return false;}//윈도우 생성 실패
  } 
  else {return false;}//SDL 초기화 실패
  
  SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");
  if(pTempSurface!=NULL)//이미지 불러오기 실패해 대한 예외처리
  {
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,pTempSurface);  
    SDL_FreeSurface(pTempSurface);
    SDL_QueryTexture(m_pTexture,NULL,NULL,&m_sourceRectangle.w,&m_sourceRectangle.h);
    m_destinationRectangle.w=m_sourceRectangle.w;
    m_destinationRectangle.h=m_sourceRectangle.h; m_destinationRectangle.x=m_sourceRectangle.x=0;
    m_destinationRectangle.y=m_sourceRectangle.y=0;
  }
  else
  {
    std::cout<<"이미지 불러오기 실패!"<<std::endl;
  }

  
  
  m_bRunning=true;
  return true;
}

void Game::Render()
{
  SDL_RenderClear(m_pRenderer);
  SDL_RenderCopy(m_pRenderer,m_pTexture,&m_sourceRectangle,&m_destinationRectangle);
  SDL_RenderPresent(m_pRenderer);
}

bool Game::Running()
{
  return m_bRunning;
}

void Game::Update()
{ 
    m_destinationRectangle.x=10;    
    m_destinationRectangle.y=10;
}

void Game::HandleEvents()
{
  SDL_Event event;//이벤트
  while(SDL_PollEvent(&event))//이벤트 전달
  {
    switch(event.type)//이벤트 타입, X를 누르면 루프문을 벗어난다.
    {
      case SDL_QUIT:
      m_bRunning=false;
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
