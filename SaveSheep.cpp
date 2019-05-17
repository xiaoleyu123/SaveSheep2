


#include <GLFW/glfw3.h>

//#include <SDL.h>
#include <SDL_image.h>
#include <SDL_TTF.H>
#include <irrklang/irrKlang.h>

#include <windows.h>
#include <iostream>
using namespace std;
using namespace irrklang;


#define  WIDE   800
#define HIGH 600


const int SCR_WIDTH = 640;
const int SCR_HEIGHT = 480;



SDL_Surface* message = NULL;
SDL_Surface* background = NULL;
//SDL_Surface* screen = NULL;


//得到窗口大小
POINT Get_ScreenSize() {


	int monitorCount;
	//GLFWmonitor* pMonitor = glfwGetPrimaryMonitor();
	GLFWmonitor** pMonitor = glfwGetMonitors(&monitorCount);

	for (int i = 0; i < monitorCount; i++) {
		int screen_x, screen_y;
		const GLFWvidmode* mode = glfwGetVideoMode(pMonitor[i]);

		POINT point;
		point.x = mode->width;
		point.y = mode->height;
		return point;

	}






}



void logSDLError(std::ostream& os, const std::string& msg) {
	os << msg << " error: " << SDL_GetError() << std::endl;
}


SDL_Texture* loadTexture(const std::string& file, SDL_Renderer* ren) {


		SDL_Texture* texture = IMG_LoadTexture(ren, file.c_str());

	
	return texture;


}




void renderTexture(SDL_Texture* tex,SDL_Renderer*ren,SDL_Rect dst,SDL_Rect*clip=nullptr) {


	SDL_RenderCopy(ren, tex, clip, &dst);

}


void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y,SDL_Rect *clip=nullptr) {


	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	if (clip != nullptr) {
		dst.w = clip->w;
		dst.h = clip->h;
	}
	else {
		SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	}


	renderTexture(tex, ren, dst, clip);



}


void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y,int w,int h) {



	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	
	dst.w = w;
	dst.h = h;
	
	SDL_RenderCopy(ren, tex, NULL, &dst);


}


void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y) {

	int w, h;
	SDL_QueryTexture(tex,NULL,NULL,&w,&h);

	renderTexture(tex, ren, x, y, w, h);


}










int main(int argc, char** argv)
{

	SDL_Surface* hello = NULL;
	SDL_Surface* screen = NULL;


	/*SDL_Surface* image, *image2;*/

	bool quit = false;
	SDL_Event event;

	/*GLFWwindow* window;*/
	///*初始化库*/
	//if (!glfwInit())
	//	return -1;

	TTF_Init();

	SDL_Window* win = SDL_CreateWindow("Save Sheep2",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 768, 0);

	/*SDL_Window* win2 = SDL_CreateWindow("Save Sheep2",
		300, 100, 1366, 768, 0);*/

	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	const std::string resPath = "Resource/";
	SDL_Texture* background = loadTexture(resPath + "background.jpg", renderer);
	SDL_Texture* image = loadTexture(resPath + "title.png", renderer);
	SDL_Rect clips[4];


	/*hello = IMG_Load("Resource/background.jpg");
	///*SDL_Surface* image = SDL_LoadBMP("image.bmp");*/
	/*SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, hello);

	SDL_FreeSurface(hello);*/
	/*SDL_Renderer* renderer2 = SDL_CreateRenderer(window, -1, 0);

	image2 = IMG_Load("Resource/Title.png");

	SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer2, image2);*/

	//play
	//cout << "纳尼" << "XX" <<"XXX" << "ZZZ\n";







	/*SDL_Color color = { 255, 255, 255 };
	TTF_Font* font = TTF_OpenFont("Microsoftbb.TTF", 30);
	SDL_Surface* surf = TTF_RenderText_Blended(font, "abc", color);
	SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, surf);*/



		//使用默认参数启动声音引擎
		ISoundEngine* engine = createIrrKlangDevice();

		//if (!engine)
		//	return 0; //引擎启动错误

		//播放一些声音流，循环播放
		engine->play2D("baby.mp3", true);

		//char i = 0;
		//std::cin >> i; // 等待用户按某个键

		//engine->drop(); //删除引擎

	

	

	
		


















	/*使窗口的上下文为当前*/
	//glfwMakeContextCurrent(window);

	//int title=0;
	while (!quit)
	{



		SDL_WaitEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}



		/* Render here */


		SDL_RenderClear(renderer);

		renderTexture(background, renderer, 0,0 ,1366,768);

		/*int iW, iH;
		SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
		int x = SCR_WIDTH / 2 - iW / 2;
		int y = SCR_HEIGHT / 2 - iH / 2;*/
		//if(title<50000)
		renderTexture(image, renderer, 400, 100,600,200);



		/*renderTexture(text,renderer,500,300,200,50);*/
		

		/*SDL_RenderCopy(renderer, text, NULL, NULL);*/


		SDL_RenderPresent(renderer);

		/*SDL_BlitSurface(hello, NULL, screen, NULL);

		SDL_Flip(screen);
*


		/*交换前后缓冲区*/
	/*	glfwSwapBuffers(window);*/

		/*轮询和处理事件*/
		glfwPollEvents();
		//title++;
		//if (title == 100000)title = 0;
	}

	/*cleanup(background, image, renderer, window);*/
	SDL_Quit();


	glfwTerminate();
	return 0;
}


