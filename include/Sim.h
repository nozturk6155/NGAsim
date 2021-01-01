#ifndef SIM_H
#define SIM_H
#include <SDL.h>

typedef class Sim
{
    public:

        ~Sim();

        // Sim is a Singleton class.
        // create the public instance function
        static Sim* Instance()
        {
            if(s_pInstance == 0)
            {
                s_pInstance = new Sim();
                return s_pInstance;
            }
        }
        // create the Window and Renderer. Initialize objects.
        bool init(const char* title, int xpos, int ypos, int width, int
                  height, int flag);

        // Draw everything to the screen
        void render();

        // Update objects' data such as position, image etc.
        void update();

        // Handle inputs
        void handleEvents();

        // Destroy objects and quit sdl
        void clean();

        bool running() { return m_bRunning; }
        void quit(){ m_bRunning = false; }

        SDL_Renderer* getRenderer() const { return m_pRenderer; }

        SimStateMachine* getStateMachine(){ return m_pSimStateMachine; }

    private:
        Sim(){}; // Ensure that noone can access it from outside of the class

        SDL_Texture* m_pTexture; // the new SDL_Texture variable
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;

        SimStateMachine* m_pSimStateMachine;

        static Sim* s_pInstance;
        bool m_bRunning;


} TheSim;

#endif // SIM_H
