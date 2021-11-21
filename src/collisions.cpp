#include "collisions.h"

bool isCollidingWithPlane(AmbientObject obj, AmbientObject plane)
{
  if ( obj.name == plane.name )
    return false;

  // planos onde x é infinito (top e bottom)
  if ( plane.bbox.x == INFINITY )
  {
    if (plane.bbox.z > 0 && (obj.bbox.z > plane.bbox.z)) return true;
    else if (plane.bbox.z < 0 && (obj.bbox.z < plane.bbox.z)) return true;
    else if (plane.bbox.y > 0 && (obj.bbox.y > plane.bbox.y)) return true;
    else if (plane.bbox.y < 0 && (obj.bbox.y < plane.bbox.y)) return true;
  }
  // planos onde y é infinito (frente e trás, esquerda e direita)
  else if ( plane.bbox.y == INFINITY )
  {
    if (plane.bbox.x > 0 && (obj.bbox.x > plane.bbox.x)) return true;
    else if (plane.bbox.x < 0 && (obj.bbox.x < plane.bbox.x)) return true;
    else if (plane.bbox.z < 0 && (obj.bbox.z < plane.bbox.z)) return true;
    else if (plane.bbox.z > 0 && (obj.bbox.z > plane.bbox.z)) return true;
  }

  return false;
}
