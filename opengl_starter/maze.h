
#include <cstdio>
#include <glm/glm.hpp>
#include <cstring>
#include <list>
#include <cmath>
#define START S
#define END W
#define MAX_SIZE 4096



struct cube
{
	glm::vec3 pos;
	short type;

cube(vec3 p,short t)
{
	pos = p;
	type = t;
}
};

class Maze
{
public:

	static const int  WALL = 0;
	static const int  TRACK = 1;
	 Maze(char* p)
	{
		path = p;
	}

	int init()
	 {
		 FILE * file = fopen(this->path, "r");
		 if (!file) { printf("%s could not be opened\n", path); return 404; }
		 printf("%s file openned\n", path);
		 char *line = static_cast<char*>(calloc(MAX_SIZE, sizeof(char)));
		 int y = 0;
		 while (fgets(line,MAX_SIZE,file))
		 {

			 for (int x=0; x < strlen(line);++x)
			 {
				 switch(line[x])
				 {
				 case '#': {
					 cubes.push_back(cube(glm::vec3(x, 0, y), WALL));
					
					 break;
				 }
				 case '\n': {
					 break;
				 }
				 case '.': {
					 cubes.push_back(cube(glm::vec3(x, 0, y), TRACK));
					 break;
				 }
				 case 'S': {
					 start = glm::vec3(x, 0, y);
					 cubes.push_back(cube(glm::vec3(x, 0, y), TRACK));
					 break;
				 }
				 case 'W': {
					 stop = glm::vec3(x,0, y);
					 cubes.push_back(cube(glm::vec3(x, 0, y), TRACK));
					 break;
				 }
				 default: {
					 printf("%d %d : Opppss... something strange!", x, y);
				 }
				 }
			 }
			 ++y;
		 }
		 fclose(file);
		 return 0;
	 }


	//Poprawic
	bool isLeggal(glm::vec3 in)
	 {
		 auto cubes = getCubes();
		 for (auto it = cubes.begin(); it != cubes.end();++it)
		 {
			 GLfloat WALL_OFFSET = 0.0001f;
			 if ((*it).type == Maze::WALL)
			 {
				 glm::vec3 vec = (*it).pos;
				 if (abs(in.x - vec.x)< 0.75f+WALL_OFFSET
				 && abs(in.z - vec.z) < 0.75f+WALL_OFFSET )  
					 return false;
			 }
		 }


		 return true;
	 }
	std::list<cube> getCubes()
	 {
		 return cubes;
	 }
	glm::vec3 getStart()
	 {
		 return start;
	 }

	glm::vec3 getStop()
	{
		return stop;
	}
private:
	std::list<cube> cubes;
	glm::vec3 start, stop;
	char* path;
};