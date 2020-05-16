#pragma once

#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class AudioManager {
protected:
    SoundBuffer buffer;
    Sound sound;
private:
    Music music;
public:
    AudioManager();
    AudioManager(bool Playmusic,const string& AudioPath);
    void PlayMusic(const string& AudioPath);
    void PlaySound(const string& AudioPath);
};
