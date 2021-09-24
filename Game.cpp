#include "Game.h"
#include "SDL_image.h"
//SDL_Texture* m_pTexture;
//SDL_Rect m_sourceRectangle;
//SDL_Rect m_destinationRectangle;
CreateTexture* pTempTexture = new CreateTexture();
CreateTexture* aTempTexture = new CreateTexture();
CreateTexture* bTempTexture = new CreateTexture();

bool Game::Init(const char* title,int xpos,int ypos,int width, int height, int flags)
{
  
  if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
  {
    m_pWindow=SDL_CreateWindow(title,xpos,ypos,width,height,flags);
    if(m_pWindow!=0)
    {
      m_pRenderer=SDL_CreateRenderer(m_pWindow,-1,0);
      if(m_pRenderer!=0)
      {
        SDL_SetRenderDrawColor(m_pRenderer,255,0,0,255);
      }
      else {return false;}//랜더러 생성 실패
    }
    else {return false;}//윈도우 생성 실패
  } 
  else {return false;}//SDL 초기화 실패
  
  SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");
  if(pTempSurface!=NULL)//이미지 불러오기 실패해 대한 예외처리
  {
    pTempTexture->Create(SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface));
    SDL_FreeSurface(pTempSurface);
    pTempTexture->QuerySourceRectangle();
    pTempTexture->InitDestinationRectangle();
    pTempTexture->SetSourceRectangle(0,0,50,50);
    pTempTexture->SetDestinationRectangle(0,0,50,50);
    std::cout<<pTempTexture->m_sourceRectangle.w<<","<<pTempTexture->m_sourceRectangle.h<<std::endl;
  }
  else
  {
    std::cout<<"이미지 불러오기 실패!"<<std::endl;
  }

  pTempSurface = SDL_LoadBMP("Assets/rider.bmp");
  if(pTempSurface!=NULL)//이미지 불러오기 실패해 대한 예외처리
  {
    aTempTexture->Create(SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface));
    SDL_FreeSurface(pTempSurface);
    aTempTexture->QuerySourceRectangle();
    aTempTexture->InitDestinationRectangle();
    aTempTexture->SetSourceRectangle(50,50,50,50);
    aTempTexture->SetDestinationRectangle(100,100,50,50);
    std::cout<<aTempTexture->m_sourceRectangle.w<<","<<aTempTexture->m_sourceRectangle.h<<std::endl;
  }
  else
  {
    std::cout<<"이미지 불러오기 실패!"<<std::endl;
  }

  pTempSurface = IMG_Load("Assets/animate-alpha.png");
  if(pTempSurface!=NULL)//이미지 불러오기 실패해 대한 예외처리
  {
    bTempTexture->Create(SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface));
    SDL_FreeSurface(pTempSurface);    
    bTempTexture->SetSourceRectangle(0,0,128,82);
    bTempTexture->SetDestinationRectangle(0,300,128,82);
    std::cout<<bTempTexture->m_sourceRectangle.w<<","<<bTempTexture->m_sourceRectangle.h<<std::endl;
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
  SDL_RenderCopy(m_pRenderer,pTempTexture->m_pTexture,&pTempTexture->m_sourceRectangle,&pTempTexture->m_destinationRectangle);
  SDL_RenderCopy(m_pRenderer,aTempTexture->m_pTexture,&aTempTexture->m_sourceRectangle,&aTempTexture->m_destinationRectangle);
  SDL_RenderCopy(m_pRenderer,bTempTexture->m_pTexture,&bTempTexture->m_sourceRectangle,&bTempTexture->m_destinationRectangle);
  SDL_RenderPresent(m_pRenderer);
}

bool Game::Running()
{
  return m_bRunning;
}

void Game::Update()
{ 
  bTempTexture->SetSourceRectangle(128 * ((SDL_GetTicks() / 200) % 6), 0,128,82);
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

void CreateTexture::Create(SDL_Texture* texture)
{
    m_pTexture = texture;
}

void CreateTexture::QuerySourceRectangle()
{
    SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
}

void CreateTexture::InitDestinationRectangle()
{
    m_destinationRectangle.x = m_sourceRectangle.x;
    m_destinationRectangle.y = m_sourceRectangle.y;
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;
}

void CreateTexture::SetSourceRectangle(int x, int y, int w, int h)
{
    m_sourceRectangle.x = x;
    m_sourceRectangle.y = y;
    m_sourceRectangle.w = w;
    m_sourceRectangle.h = h;
}

void CreateTexture::SetDestinationRectangle(int x, int y, int w, int h)
{
    m_destinationRectangle.x = x;
    m_destinationRectangle.y = y;
    m_destinationRectangle.w = w;
    m_destinationRectangle.h = h;
}
