#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <filesystem>
#include <iostream>
#include <memory>

// Constructor with member initializer list
Game::Game()
    : raccoon("../assets/raccoon.png", 0, 0), currentState(StartScreen) {
  std::cout << "Game constructor called!" << std::endl;
}

void Game::start(sf::RenderWindow &window) {
  isRunning = true;
  currentState = StartScreen; // Ensure we start with the start screen
  // load startscreen assets
  if (!startingBackgroundTexture.loadFromFile(
          "../assets/startBackground.png")) {
    std::cerr << "Failed to load background!" << std::endl;
    std::cerr << "Current working directory might be wrong" << std::endl;
    // Don't continue if font fails to load
    return;
  }
  std::cout << "Background loaded successfully!" << std::endl;

  startingBackgroundSprite =
      std::make_unique<sf::Sprite>(startingBackgroundTexture);
  startingBackgroundSprite->setTexture(startingBackgroundTexture);
  startingBackgroundSprite->setPosition(sf::Vector2f(0.f, 0.f));

  // compute background scale


  if (startingBackgroundTexture.getSize().x > 0 &&
      startingBackgroundTexture.getSize().y > 0) {
    window.draw(*startingBackgroundSprite);
    std::cout << "Drawing background sprite" << std::endl;
  } else {
    std::cout << "Background texture not loaded, skipping draw" << std::endl;
  }

  // Import font
  std::cout << "Attempting to load font..." << std::endl;
  if (!font.openFromFile("../assets/fonts/Conthrax-SemiBold.otf")) {
    std::cerr << "Failed to load font!" << std::endl;
    std::cerr << "Current working directory might be wrong" << std::endl;
    // Don't continue if font fails to load
    return;
  }
  std::cout << "Font loaded successfully!" << std::endl;

  // Setup text
  nameText = std::make_unique<sf::Text>(font, sf::String("NameText"), 20);
  nameText->setFillColor(sf::Color::White);
  nameText->setPosition(sf::Vector2f(10.f, 10.f));

  healthText = std::make_unique<sf::Text>(font, sf::String("HealthText"), 20);
  healthText->setFillColor(sf::Color::White);
  healthText->setPosition(sf::Vector2f(10.f, 40.f));

  scoreText = std::make_unique<sf::Text>(font, sf::String("ScoreText"), 20);
  scoreText->setFillColor(sf::Color::White);
  scoreText->setPosition(sf::Vector2f(10.f, 80.f));

  // set initial values of texts
  nameText->setString(" Name: " + player.getPlayerName());
  healthText->setString(" Health: " + std::to_string(player.health));
  scoreText->setString("Racoons collected: " + std::to_string(player.score));

  // set game background
  if (!backgroundTexture.loadFromFile("../assets/landing.png")) {
    std::cerr << "Failed to load background!" << std::endl;
    std::cerr << "Current working directory might be wrong" << std::endl;
    // Don't continue if font fails to load
    return;
  }
  std::cout << "Background loaded successfully!" << std::endl;

  // Set the texture on the sprite AFTER loading
  backgroundSprite = std::make_unique<sf::Sprite>(backgroundTexture);
  backgroundSprite->setTexture(backgroundTexture);
  backgroundSprite->setPosition(sf::Vector2f(0.f, 0.f));


  // calculate scales

  sf::Vector2u windowSize = window.getSize();
  sf::Vector2u textureSize = backgroundTexture.getSize();

  float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
  float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

  startingBackgroundSprite->setScale(sf::Vector2f(scaleX/4, scaleY/4));

  backgroundSprite->setScale(sf::Vector2f(scaleX, scaleY));

  std::cout << "Game started" << std::endl;

  // Create obstacles
  obstacles.reserve(4);
  obstacles.emplace_back("../assets/Alien2.png", 650, 600, 300, 600);
  obstacles.emplace_back("../assets/Alien1.png", 350, 600, 400, 600);
  obstacles.emplace_back("../assets/Alien1.png", 143, 600, 300, 600);
  obstacles.emplace_back("../assets/Alien2.png", 820, 650, 200, 700);

  // Create raccoons
  raccoons.reserve(4);
  raccoons.emplace_back("../assets/raccoon.png", 550, 650);
  raccoons.emplace_back("../assets/raccoon.png", 220, 660);
  raccoons.emplace_back("../assets/raccoon.png", 700, 630);
  raccoons.emplace_back("../assets/raccoon.png", 760, 640);

  // Initialize starting screen elements
  titleText = std::make_unique<sf::Text>(font, "SPACE RACOON", 48);
  titleText->setFillColor(sf::Color::White);
  titleText->setPosition(sf::Vector2f(300.f, 200.f));

  inputPromptText = std::make_unique<sf::Text>(font, "Enter your name:", 24);
  inputPromptText->setFillColor(sf::Color::White);
  inputPromptText->setPosition(sf::Vector2f(320.f, 350.f));

  playerNameText = std::make_unique<sf::Text>(font, "", 24);
  playerNameText->setFillColor(sf::Color::White);
  playerNameText->setPosition(sf::Vector2f(350.f, 400.f));

  startButtonText =
      std::make_unique<sf::Text>(font, "Press ENTER to Start", 24);
  startButtonText->setFillColor(sf::Color::White);
  startButtonText->setPosition(sf::Vector2f(300.f, 500.f));

  playerNameInput = "";
  isTyping = false;
}

void Game::update() {
  if (currentState == StartScreen) {
    // Handle text input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Backspace) &&
        !playerNameInput.empty()) {
      playerNameInput.pop_back();
      playerNameText->setString(playerNameInput);
    }

    // Handle Enter key to start game
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) &&
        !playerNameInput.empty()) {
      player.setPlayerName(playerNameInput);
      currentState = Playing;
    }
  }

  if (currentState == Playing) {
    // save players position before moving
    sf::Vector2f playerPosition = player.avatarSprite->getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
      player.move(Player::UP);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
      player.move(Player::LEFT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
      player.move(Player::DOWN);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
      player.move(Player::RIGHT);
    }

    // Update text each frame (in case health/score changes)
    healthText->setString(" Health: " + std::to_string(player.health));
    scoreText->setString(" Raccoons collected: " +
                         std::to_string(player.score));

    std::cout << "Game updated" << std::endl;

    for (auto &obstacle : obstacles) {
      obstacle.update();
    }

    for (auto &raccoon : raccoons) {
      if (!raccoon.isCollected) {
        checkRaccoonCollision();
        raccoon.update();
      }
    }

    checkObstacleCollision();
  }
}

void Game::render(sf::RenderWindow &window) {
  if (currentState == StartScreen) {
    // Draw starting background
    if (startingBackgroundTexture.getSize().x > 0) {
      window.draw(*startingBackgroundSprite);
    }

    // Draw starting screen elements
    window.draw(*titleText);
    window.draw(*inputPromptText);
    window.draw(*playerNameText);
    window.draw(*startButtonText);
  }

  if (currentState == Playing) {
    // Check if texture is loaded before drawing
    if (backgroundTexture.getSize().x > 0 &&
        backgroundTexture.getSize().y > 0) {
      window.draw(*backgroundSprite);
      std::cout << "Drawing background sprite" << std::endl;
    } else {
      std::cout << "Background texture not loaded, skipping draw" << std::endl;
    }

    for (auto &obstacle : obstacles) {
      obstacle.draw(window);
    }

    player.draw(window);
    window.draw(*nameText);
    window.draw(*healthText);
    window.draw(*scoreText);

    for (auto &raccoon : raccoons) {
      if (!raccoon.isCollected) {
        raccoon.draw(window);
      }
    }

    std::cout << "Game rendered" << std::endl;
  }
}

void Game::checkObstacleCollision() {
  sf::FloatRect playerBounds = player.avatarSprite->getGlobalBounds();

  for (auto &obstacle : obstacles) {
    sf::FloatRect obstacleBounds = obstacle.obstacleSprite->getGlobalBounds();
    if (playerBounds.findIntersection(obstacleBounds)) {
      player.health -= 10;
      std::cout << "Player hit an obstacle!" << std::endl;
      break;
    }
  }
}

void Game::checkRaccoonCollision() {
  sf::FloatRect playerBounds = player.avatarSprite->getGlobalBounds();
  for (auto &raccoon : raccoons) {
    if (raccoon.isCollected)
      continue;

    sf::FloatRect raccoonBounds = raccoon.raccoonSprite->getGlobalBounds();
    if (playerBounds.findIntersection(raccoonBounds)) {
      player.score += 1;
      raccoon.isCollected = true;
      std::cout << "Player hit a raccoon!" << std::endl;
      break;
    }
  }
}

void Game::handleEvent(const sf::Event &event) {
  if (currentState == StartScreen) {
    if (event.is<sf::Event::TextEntered>()) {
      // In SFML 3.x, use getIf instead of get
      if (const auto *textEvent = event.getIf<sf::Event::TextEntered>()) {
        if (textEvent->unicode >= 32 &&
            textEvent->unicode <= 126) { // Printable characters
          playerNameInput += static_cast<char>(textEvent->unicode);
          playerNameText->setString(playerNameInput);
        }
      }
    }
  }
}