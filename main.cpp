#include <SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>  
//cstdlib와 ctime은 랜덤함수를 사용하기 위해서
//함수 선언
bool Init(const char* title,int xpos,int ypos,int height, int width, int flags);
void Render();
void RandColor();//랜덤한 색깔을 생성
void Update();//업데이트
void UserInput();//사용자 입력
//전역변수
SDL_Window* g_pWindow =0;
SDL_Renderer* g_pRenderer=0;
bool g_bRunning = false;//윈도우가 생성되지 않으면 랜더링 하지 않기 위한 변수

int main(int argc, char* args[])
{
 
  if(Init("Breaking Up HelloSDL",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_SHOWN))
  {
    g_bRunning=true;
  }
  else
  {
    return 1;//에러 코드 발생
  }
  while(g_bRunning)//윈도우가 생성됫다면 하나의 루프를 형성함
  {  
    UserInput();//사용자 입력
    Update();//안에 있는 함수를 호출 시킴
    Render();//화면을 출력함
  }
  SDL_Quit();
  return 0;
}
bool Init(const char* title,int xpos,int ypos,int height, int width, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
  {
    g_pWindow=SDL_CreateWindow(title,xpos,ypos,height,width,flags);
    if(g_pWindow!=0)
    {
      g_pRenderer=SDL_CreateRenderer(g_pWindow,-1,0);
    }
  }
  else
  {
    return false;
  }
  SDL_SetRenderDrawColor(g_pRenderer,0,0,0,255);
  
  return true;
}
void Render()
{
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
}
void RandColor()
{
  srand((unsigned int)time(NULL)); 
  SDL_SetWindowSize(g_pWindow,rand()%640,rand()%480);//윈도우 크기 변경
  SDL_SetRenderDrawColor(g_pRenderer,rand()%255,rand()%255,rand()%255,255);//윈도우 색깔 변경
}
void Update()
{  
  RandColor();//랜덤한 색을 생성
}
void UserInput()
{
  SDL_Event event;//이벤트
  while(SDL_PollEvent(&event))//이벤트 전달
  {
    switch(event.type)//이벤트 타입, X를 누르면 루프문을 벗어난다.
    {
      case SDL_QUIT:
      g_bRunning=false;
      break;
    }
  }
}
//SDL_WINDOWPOS_CENTERED