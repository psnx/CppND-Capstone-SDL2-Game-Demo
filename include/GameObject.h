#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

struct Transform{
    int x{0};
    int y{0};
};

class GameObject {
private:
    /* data */
public:
    GameObject(/* args */);
    ~GameObject();
    Transform transform;
    virtual void Update();
    virtual void Draw();
};

#endif