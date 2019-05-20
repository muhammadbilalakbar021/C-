#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Weapon
{
public:
    Weapon();
    Weapon(int attack_min_, int attack_max_, const string &name_);

    virtual int attack()
    {
        int i=rand();
        return (i % (attack_max_-attack_min_))+attack_min_;
    }

    int getAttack_min_() const;
    void setAttack_min_(int attack_min_);
    int getAttack_max_() const;
    void setAttack_max_(int attack_max_);
    const string &getName_() const;
    void setName_(const string &name_);

private:
    int attack_min_;
    int attack_max_;
    string name_;
};

class Dagger : public Weapon{
public:
    Dagger();
    Dagger(int attack_min_, int attack_max_, const string &name_, double crit_, double crit_dice_);

    double getCrit_() const;
    void setCrit_(double crit_);
    double getCrit_dice_() const;
    void setCrit_dice_(double crit_dice_);

    int attack()
    {
        int i=rand()%20+1;
        srand((unsigned)time(0));
        if (i>=crit_dice_)
        {
            return ((rand() % (getAttack_max_()-getAttack_min_()))+getAttack_max_())*crit_dice_;

        } else
        {
            return ((rand() % (getAttack_max_()-getAttack_min_()))+getAttack_max_());

        }

    }


private:
    double crit_;
    double crit_dice_;
};

class ShortSword: public Weapon{
public:
    ShortSword();
    ShortSword(int attack_min_, int attack_max_, const string &name_, int multiplier_);

    int attack()
    {
        srand((unsigned)time(0));
        int i=rand()% multiplier_+1;
        if (i==multiplier_)
        {
            return (i % (getAttack_max_()-getAttack_min_())+getAttack_max_())*multiplier_;
        } else
        {
            return ((i % (getAttack_max_()-getAttack_min_()))+getAttack_max_());
        }

    }


    int getMultiplier_() const;
    void setMultiplier_(int multiplier_);

private:
    int multiplier_;
};

class Enemy{
public:
    Enemy(const string &name_, const int &health_);
    Enemy();

    const string &getName_() const;
    void setName_(const string &name_);
    int getHealth_() const;
    void setHealth_(int health_);

    void receiveAttack(Weapon* weapon )
    {
        int i=weapon->attack();
        setHealth_(getHealth_()-i);
        cout << weapon->getName_() <<" Dealt <" <<i<<"> damage to " << getName_() << endl;
    }

private:
    string name_;
    int health_;
};
