#pragma once

#include "Shader.h"

#ifndef GLEW_STATIC
#define GLEW_STATIC 1
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include <cstring>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>


class objMesh
{
private:
	void loadObj(const char* path);

	std::vector<glm::vec3> out_vertices;
	std::vector<glm::vec3> out_normals;
	std::vector<glm::vec2> out_uvs;

	unsigned int VAO;
	unsigned int vertices_VBO;
	unsigned int normals_VBO;
	unsigned int uvs_VBO;

	int vertexCount;

	glm::vec3 color;

	void Bind();
	void Unbind();
	void init();


	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	glm::mat4 part;
	glm::mat4 worldMatrix;

public:
	objMesh(
		string path, 
		glm::vec3 _color = glm::vec3(1.f),
		glm::vec3 _position = glm::vec3(0.f),
		glm::vec3 _scale = glm::vec3(1.f),
		glm::vec3 _rotation = glm::vec3(0.f)
	);
	~objMesh();


	void updatePartMatrix();
	void applyGroup(glm::mat4 groupMatrix);
	void draw(Shader* sh, unsigned int type);

};

