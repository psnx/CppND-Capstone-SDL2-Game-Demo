#ifndef VECTOR2D_H
#define VECTOR2D_H

template<class T>
struct Vector2d {
  T X{0};
  T Y{0};
  static T DotProduct (const Vector2d one, const Vector2d two){
    return (one.X * two.X + one.Y * two.Y);
  }
};

#endif