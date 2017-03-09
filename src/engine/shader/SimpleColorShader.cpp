#include "SimpleColorShader.h"

void SimpleColorShader::render(const std::shared_ptr<Entity> entity)
{
	start();

	loadToUniform(location_transformationMatrix, GLMath::createTransformationMatrix(entity->getPosition(), entity->getRotation(), entity->getScale()));

	glBindVertexArray(entity->getModel()->getMesh()->getVAOID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(3);

	glDrawElements(GL_TRIANGLES, entity->getModel()->getMesh()->getIndices().size(), GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glEnableVertexAttribArray(3);
	glBindVertexArray(0);

	stop();
}