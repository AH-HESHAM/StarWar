#include "Game.h"
#include <GL/freeglut.h>
#include "../Drawer/Drawer.cpp"
#include <sstream>
#include <iostream>

void renderBitmapString(float x, float y, void *font, const char *string);
bool Game::gameIsRunning = false;
int Game::score = 0;
int Game::spawns = 0;
vector<string> Game::endGameText;
void Game::startGame() {
    gameIsRunning = true;
    drawer.drawerInitializer([this](float score, float spawns) { this->endGame(score, spawns); });
    glutDisplayFunc(Drawer::drawSceneWrapper);
    glutKeyboardFunc(Drawer::keyboardUpdate);
}

struct Particle {
    float position[3];
    float velocity[3];
    float color[4]; // RGBA color
    float life; // lifespan of the particle
};

std::vector<Particle> particles;

// Function to initialize particles at the destruction point
void initParticles(float x, float y, float z) {
    particles.clear();
    int numParticles = 500; // Increased number of particles
    for (int i = 0; i < numParticles; ++i) {
        Particle p;
        p.position[0] = x;
        p.position[1] = y;
        p.position[2] = z;
        p.velocity[0] = ((float) rand() / RAND_MAX) * 2.0f - 1.0f;
        p.velocity[1] = ((float) rand() / RAND_MAX) * 2.0f - 1.0f;
        p.velocity[2] = ((float) rand() / RAND_MAX) * 2.0f - 1.0f;
        p.color[0] = 1.0f; // Bright red
        p.color[1] = 0;
        p.color[2] = 0.0f; // Red (no blue)
        p.color[3] = 1.0f; // Alpha (fully opaque)
        p.life = 1.5f; // 1.5 seconds lifespan
        particles.push_back(p);
    }
}
// Function to update particle positions
void updateParticles(float deltaTime) {
    for (auto& p : particles) {
        p.position[0] += p.velocity[0] * deltaTime;
        p.position[1] += p.velocity[1] * deltaTime;
        p.position[2] += p.velocity[2] * deltaTime;
        p.life -= deltaTime;
        p.color[3] = p.life / 1.5f; // Fade out effect based on remaining life
    }
    // Remove dead particles
    particles.erase(std::remove_if(particles.begin(), particles.end(), [](Particle& p) { return p.life <= 0.0f; }), particles.end());
}

void Game::nextView(int score, int spawns) {
    endGameText.emplace_back("Game is over\n");
    endGameText.push_back("Score: " + to_string(score) + "\n");
    if (ModeUtility::isTimerMode())
        endGameText.push_back("Number of respawns: " + to_string(spawns) + "\n");
    endGameText.emplace_back("Press ESC to exit");

    // Set the display function to the end game screen
    glutDisplayFunc(Game::drawEndGameScreen);
    glutPostRedisplay();
}
void update(int numberOfOperations) {
    if(numberOfOperations == 100) {
        glEnable(GL_LIGHTING);
        Game::nextView(Game::score, Game::spawns);
        return;
    }
    // Update particles
    float deltaTime = 0.016f; // assuming 60 FPS
    updateParticles(deltaTime);

    // Schedule next update
    glutTimerFunc(16, update, numberOfOperations + 1);
}

void createParticles() {
    // Replace these coordinates with your spacecraft's position
    float spacecraftPosX = 0.0f;
    float spacecraftPosY = 0.0f;
    float spacecraftPosZ = -5.0f;
    initParticles(spacecraftPosX, spacecraftPosY, spacecraftPosZ);
    glutTimerFunc(16, update, 0); // Schedule the first update
}

void renderParticles() {
    glPointSize(6.0f); // Increase point size for visibility
    glBegin(GL_POINTS);
    for (auto& p : particles) {
        glColor4fv(p.color);
        glVertex3fv(p.position);
    }
    glEnd();
}

// Display callback function
void display() {
    // Clear the color buffer and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDisable(GL_LIGHTING);
    // Render particles
    renderParticles();

    glutSwapBuffers();
    glutPostRedisplay();
}


void Game::fireTheGameEndEvent() {
    glViewport(0, 0, 700, 700);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-2.0, 2.0, -2.0, 2.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    createParticles();
}


void Game::endGame(float givenScore, float givenSpawns) {
    gameIsRunning = false;
    this->score = givenScore;
    this->spawns = givenSpawns;
    fireTheGameEndEvent();
    glutDisplayFunc(display);


}


bool Game::isGameRunning() {
    return gameIsRunning;
}

void Game::drawEndGameScreen() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

    // Set up orthographic projection for 2D text rendering
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    // Push the current color onto the attribute stack
    glPushAttrib(GL_CURRENT_BIT);

    // Set text color
    glColor3f(1.0, 0.0, 1.0);

    // Render text
    float x = 250;
    float y = glutGet(GLUT_WINDOW_HEIGHT) - 250;
    for (const auto &line : endGameText) {
        renderBitmapString(x, y, GLUT_BITMAP_HELVETICA_18, line.c_str());
        y -= 20.0f;
    }

    // Pop the color off the attribute stack
    glPopAttrib();
    glutSwapBuffers();
}

vector<std::string> & Game::getEndGameText() {
    return endGameText;
}

void renderBitmapString(float x, float y, void *font, const char *string) {
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
