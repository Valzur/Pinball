#pragma once

#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class AudioManager {
private:
    SoundBuffer buffer;
    Sound sound;
    Music music;
public:
    AudioManager();
    AudioManager(bool Playmusic,const string& AudioPath);
    void PlayMusic(const string& AudioPath);
    void PlaySound(const string& AudioPath);
};
