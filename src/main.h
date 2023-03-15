#define ROTATION_ANGLE 0.003 //vitesse de rotation
#define CAMERA_SPEED 0.05   //vitesse à laquelle on avance

int SCREEN_WIDTH=620; //largeur de la fenêtre par défaut
int SCREEN_HEIGHT=480; //hauteur de la fenêtre par défaut
const double CAMERA_FOV=0.66; //fov 

//description de la map (tableau 2d -> 0=vide 1=mur)
int map[20][20]={
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,1,0,1,0,1,1,1,1,1,1,0,1},
    {1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1},
    {1,1,1,1,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1},
    {1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,1,0,1},
    {1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,1,1,1,0,1},
    {1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,1,1,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

//vecteur 2 dimensions avec composante flottante
typedef struct{
    float x,y;
}vector2f;

//structure de la caméra
typedef struct{
    vector2f position; //vecteur position
    vector2f direction; //vecteur direction
    vector2f plane;  //vecteur plan (orthogonal à la direction)
    vector2f leftRayDir; // leftRayDir=direction-plane 
    float angle; //angle radian
}camera;