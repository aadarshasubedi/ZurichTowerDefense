#include "Application.h"
#include "State.h"
#include "StringHelpers.h"
#include "GameState.h"
#include "MenuState.h"
#include "TitleState.h"
#include "PauseState.h"
#include "SettingsState.h"
#include "typedefs.h"
#include "Constants.h"
#include <ratio>

const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);

using namespace GraphicsConstants;

Application::Application()
    : mWindow(sf::VideoMode(getAbsoluteWidth(), getAbsoluteHeight()), "ZTD", sf::Style::Close)
    , mTextures()
    , mFonts()
    , mPlayer()
    , mStateStack(State::Context(mWindow, mTextures, mFonts, mPlayer))
    , mStatisticsText()
    , mStatisticsUpdateTime()
    , mStatisticsNumFrames(0)
{
    mWindow.setKeyRepeatEnabled(false);

    // Fonts
    mFonts.load(Fonts::Main, "Sansation.ttf");

    // Backgrounds
    mTextures.load(Textures::TitleScreen, "TitleScreen.png");
    mTextures.load(Textures::ButtonNormal, "ButtonNormal.png");
    mTextures.load(Textures::ButtonPressed, "ButtonPressed.png");
    mTextures.load(Textures::ButtonSelected, "ButtonSelected.png");
    mStatisticsText.setFont(mFonts.get(Fonts::Main));
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(10u);

    registerStates();
    mStateStack.pushState(States::Title);
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            processInput();
            update(TimePerFrame);

            // Check inside this loop, because stack might be empty before update() call
            if (mStateStack.isEmpty())
                mWindow.close();
        }

        updateStatistics(dt);
        render();
    }
}

void Application::processInput()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        mStateStack.handleEvent(event);

        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Application::update(sf::Time dt)
{
    mStateStack.update(dt);
}

void Application::render()
{
    mWindow.clear();

    mStateStack.draw();

    mWindow.setView(mWindow.getDefaultView());
    mWindow.draw(mStatisticsText);

    mWindow.display();
}

void Application::updateStatistics(sf::Time dt)
{
    mStatisticsUpdateTime += dt;
    mStatisticsNumFrames += 1;
    if (mStatisticsUpdateTime >= sf::seconds(1.0f))
    {
        mStatisticsText.setString("FPS: " + toString(mStatisticsNumFrames));

        mStatisticsUpdateTime -= sf::seconds(1.0f);
        mStatisticsNumFrames = 0;
    }
}

void Application::registerStates()
{
    mStateStack.registerState<TitleState>(States::Title);
    mStateStack.registerState<MenuState>(States::Menu);
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<PauseState>(States::Pause);
    mStateStack.registerState<SettingsState>(States::Settings);
}