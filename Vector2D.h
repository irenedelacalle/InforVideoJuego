#pragma once
class Vector2D
{
public:
 float x;
 float y;

 //Vector2D(void);
 //~Vector2D(void);


  Vector2D(float xv=0.0f,float yv=0.0f); // (1)
  virtual ~Vector2D();
  float modulo(); // (2) modulo del vector
  float argumento(); // (3) argumento del vector
  Vector2D Unitario(); // (4) devuelve un vector unitario
  Vector2D operator - (Vector2D &); // (5) resta de vectores
  Vector2D operator + (Vector2D &); // (6) suma de vectores
  Vector2D operator + (float);
  float operator *(Vector2D &); // (7) producto escalar
  Vector2D operator *(float); 
  Vector2D unitario();

};
