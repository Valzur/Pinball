#include "AudioManager.h"

void AudioManager::PlaySound(const string& AudioPath) {
    SoundBuffer buffer1;
    if (!buffer1.loadFromFile(AudioPath))
        cout<<"Error, Can't load sound file!" << endl;
    sound.setBuffer(buffer1);
    sound.setLoop(false);
    sound.setVolume(50.0);
    sound.play();
}

void AudioManager::PlayMusic(const string&) {
    if (!music.openFromFile("../Audio/NEFFEX - Dangerous [Copyright Free].ogg"))
        cout << "Error, Can't load music file!" << endl;
    music.play();
    music.setLoop(true);
}

AudioManager::AudioManager(bool Playmusic, const string& AudioPath) {

    if(Playmusic) {
        //PlayMusic(AudioPath);
    }

}
