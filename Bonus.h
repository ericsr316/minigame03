#ifndef BONUS_H_INCLUDED
#define BONUS_H_INCLUDED

class Bonus
{
private:

    char icon;
    int bonus;

public:

    Bonus()
    {

    };

    Bonus(char i, int b)
    :
    icon(i), bonus(b){
    }

    void setIcon(char i)
    {
        icon = i;
    }

    char getIcon()
    {
        return icon;
    }

    void setBonus(int b)
    {
        bonus = b;
    }

    int getBonus()
    {
        return bonus;
    }

    void debug()
    {
        std::cout<<"Debug [ "<<getIcon()<<"  "<<getBonus()<<" ]\n";
    }
};


#endif // BONUS_H_INCLUDED
