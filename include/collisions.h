#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <stack>
#include <map>
#include <list>

// Headers da biblioteca GLM: criação de matrizes e vetores.
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>

// objetos para cálculo de colisão
struct AmbientObject
{
    std::string name;
    glm::vec3 bbox;
};

bool isCollidingWithPlane(AmbientObject obj, AmbientObject plane);
