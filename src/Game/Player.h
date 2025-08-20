class Player {
    public:
    int health;
    int score;
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    void move(Direction direction);
    private:
    int x, y;

    sf::RectangleShape avatar;

};                  