#pragma once
#include "DrawableItem.h"
#include "SoundAnalyzer.h"
#include "common\EsgiShader.h"
#include "Analyzers.h"

class Map : public DrawableItem
{
public:
						Map(SoundAnalyzer& Sound);
	void				Draw(const glm::mat4x4& projectionMatrix, const glm::mat4x4& viewMatrix, const glm::mat4x4& worldTransform, const float& time) const;
	void				Destroy();
						~Map();
private:
	void				GetData(int FunctionIndex, NormalizedDataResult& result);
	void				GenTexture(const char* textureName);
	void				ConstructEBO();
	void				ConstructVBO();
	void				FillVectorVBO(const int startIndex, const int endIndex, const NormalizedDataResult& dataSource, std::vector<float>& vertex);
	void				FillVectorEBO(const int startIndex, const int endIndex, std::vector<unsigned int>& ind);

	SoundAnalyzer		RefSound;
	float				NumberRow;
	float				NumberColumn;
	GLuint				TextureBuffer;
	GLuint				EBO;
	GLuint				VBO;
	GLuint				ShaderProgram;
	EsgiShader			Shader;
};