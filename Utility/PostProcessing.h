#pragma once
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/Texture.hpp>

using namespace std;

class PostProcessing {
private:
    sf::Texture *PreTexture;
    sf::Texture PostTexture;
    sf::Shader shader;

public:
    //Setters
    void SetPreTexture(sf::Texture * preTexture);

    //Getters
    sf::Texture* GetPostTexture();

    //Effects
    void blur();
    void Bloom();
};
//The bloom process takes 3 steps:
//1: Save all bright pixels from the scene (= luminescence)
//2: Apply a blur effect on those pixels (= blur)
//3: draw original picture and the blur texture on top (= assemble)
