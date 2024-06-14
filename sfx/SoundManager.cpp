/*
* To use the 3 available sound effects create an object of the SoundManager and call playSound
* pass 1 for destroy, 2 for ui background, 3 for shooting
* To run you need to link winm.lib with the project by a terminal command
* If sounds don't work at the same time try SND_SYNC instead
**/
#include "SoundManager.h"
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")


const std::string SoundManager::soundFilePath_destroy = "./assets/destroy.wav";
const std::string SoundManager::soundFilePath_ui = "./assets/ui.wav";
const std::string SoundManager::soundFilePath_shooting = "./assets/shooting.wav";


void SoundManager::playSound(int type) {
    switch (type) {
    case 1:
if (PlaySound(soundFilePath_destroy.c_str(), NULL, SND_FILENAME | SND_ASYNC)) {
        std::cout << "Playing sound file: " << soundFilePath_destroy << std::endl;
    } else {
        std::cerr << "Failed to play sound file: " << soundFilePath_destroy << std::endl;
    }        break;
    case 2:
if (PlaySound(soundFilePath_ui.c_str(), NULL, SND_FILENAME | SND_ASYNC)) {
        std::cout << "Playing sound file: " << soundFilePath_ui << std::endl;
    } else {
        std::cerr << "Failed to play sound file: " << soundFilePath_ui << std::endl;
    }        break;
    case 3:
if (PlaySound(soundFilePath_shooting.c_str(), NULL, SND_FILENAME | SND_ASYNC)) {
        std::cout << "Playing sound file: " << soundFilePath_shooting << std::endl;
    } else {
        std::cerr << "Failed to play sound file: " << soundFilePath_shooting << std::endl;
    }        break;
    
}
