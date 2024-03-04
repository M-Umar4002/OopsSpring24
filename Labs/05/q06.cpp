#include <iostream>
using namespace std;

class GraphicsRenderingEngine {
    public :
        void renderGraphics() {
            cout << "Rendering graphics" << endl;
        }
};

class InputHandler {
    public :
        void handleInput() {
            cout << "Handling Input" << endl;
        }
};

class PhysicsEngine {
    public :
        void simulatePhysics() {
            cout << "Simulating Physics" << endl;
        }
};

class GameEngine {
    GraphicsRenderingEngine grReEngine;
    InputHandler inputHandler;
    PhysicsEngine phyEngine;
    
    public :
        void run() {
            cout << "Starting game engine" << endl;
            grReEngine.renderGraphics(), inputHandler.handleInput(), phyEngine.simulatePhysics();
            cout << "Game engine closed" << endl;
        }
};

int main() {
    GameEngine game;
    game.run();

    return 0;
}
