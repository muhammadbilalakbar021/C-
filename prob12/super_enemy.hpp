
class Enemy
{
public:
    Enemy(int xpos_, int ypos_, int health_, int strength_, int defense_);

    Enemy();

    int getXpos_() const;

    void setXpos_(int xpos_);

    int getYpos_() const;

    void setYpos_(int ypos_);

    int getHealth_() const;

    void setHealth_(int health_);

    int getStrength_() const;

    void setStrength_(int strength_);

    int getDefense_() const;

    void setDefense_(int defense_);

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void levelUp();

    void display();

private:
    int xpos_;
    int ypos_;
    int health_;
    int strength_;
    int defense_;

};

class SuperEnemy:public Enemy
{
public:
    SuperEnemy();

    SuperEnemy(int xpos_, int ypos_, int health_, int strength_, int defense_);

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void levelUp();

    void display();


};
