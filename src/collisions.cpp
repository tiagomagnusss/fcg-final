#include "collisions.h"

bool isCollidingWithPlane(AmbientObject obj, PlaneObject plane)
{
  if ( obj.name == plane.name )
    return false;

  // planos onde x é infinito (top e bottom)
  if ( plane.bbox.x == INFINITY )
  {
    if (plane.bbox.z > 0 && ( (obj.bbox_max.z + obj.bbox_min.z) > plane.bbox.z)) return true;
    else if (plane.bbox.z < 0 && ((obj.bbox_max.z - obj.bbox_min.z) < plane.bbox.z)) return true;
    else if (plane.bbox.y > 0 && ((obj.bbox_max.y + obj.bbox_min.y)/2 > plane.bbox.y)) return true;
    else if (plane.bbox.y < 0 && ((obj.bbox_max.y + obj.bbox_min.y) < plane.bbox.y)) return true;
  }
  // planos onde y é infinito (frente e trás, esquerda e direita)
  else if ( plane.bbox.y == INFINITY )
  {
    // frente
    if (plane.bbox.x > 0 && ((obj.bbox_max.x + obj.bbox_min.x)/2 > plane.bbox.x)) return true;
    // trás
    else if (plane.bbox.x < 0 && ((obj.bbox_max.x + obj.bbox_min.x)/2 < plane.bbox.x)) return true;
    // direita
    else if (plane.bbox.z > 0 && ((obj.bbox_max.z + obj.bbox_min.z)/2 > plane.bbox.z)) return true;
    // esquerda
    else if (plane.bbox.z < 0 && ((obj.bbox_max.z + obj.bbox_min.z)/2 < plane.bbox.z)) return true;
  }
  // colisão do touchdown
  else
  {
     if (plane.bbox.z < 0 && ((obj.bbox_max.z + obj.bbox_min.z)/2 <= plane.bbox.z)) return true;
  }

  return false;
}

bool objectsColliding(AmbientObject obj1, AmbientObject obj2)
{
  if ( obj1.name == obj2.name )
    return false;

  // if ( ( std::abs(obj1.bbox.x - obj2.bbox.x) < (obj1.bbox.x + obj2.bbox.x) ) )
  // {
  //   return true;
  // }

  return false;
}
