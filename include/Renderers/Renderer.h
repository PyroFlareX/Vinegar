#ifndef RENDERER_H
#define RENDERER_H

#include "../Camera.h"
#include "CubeRenderer.h"
#include "ComputeRenderer.h"
#include "ChunkRenderer.h"


class Renderer
{
    public:
        Renderer();

		void drawCube(Entity& entity);
		void doCompute();
		//void drawChunk(ChunkMesh& mesh);
		void render(Camera& cam);

        ~Renderer();
    protected:

    private:
		CubeRenderer m_cubeRenderer;
		ComputeRenderer m_computeRenderer;
		ChunkRenderer m_chunkRenderer;
};

#endif // RENDERER_H
