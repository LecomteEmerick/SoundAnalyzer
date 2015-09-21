#pragma once
#include "DrawableItem.h"
#include "SoundAnalyzer.h"
#include "common\EsgiShader.h"

class Map : public DrawableItem
{
public:
					Map(SoundAnalyzer& Sound);
	void			Draw(const glm::mat4x4& projectionMatrix, const glm::mat4x4& viewMatrix, const glm::mat4x4& worldTransform, const float& time) const;
	void			Destroy();
					~Map();
private:
	void			GenTexture(const char* textureName);
	void			ConstructEBO();
	void			ConstructVBO();
	SoundAnalyzer	RefSound;
	float			Length;
	GLuint			TextureBuffer;
	GLuint			EBO;
	GLuint			VBO;
	GLuint			ShaderProgram;
	EsgiShader		Shader;
};

