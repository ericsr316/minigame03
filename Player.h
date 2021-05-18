#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{

private:

    char avatar;
    std::string user;
    int score = 0;


public:
    Player()
    {

    };

    Player(char a, std::string u):
        avatar(a),user(u)
    {
    };


    void setAvatar(char a)
    {
        avatar = a;
    }

    char getAvatar()
    {
        return avatar;
    }

    void setUser(std::string u)
    {
        user = u;
    }

    std::string getUser()
    {
        return user;
    }

    void setScore(int s)
    {
        score = s;
    }

    int getScore()
    {
        return score;
    }

    void debug()
    {
        std::cout<<"debug ["<<getUser()<<" "<<getAvatar()<<"]";
    }
};


#endif // ROBOT_H_INCLUDED
