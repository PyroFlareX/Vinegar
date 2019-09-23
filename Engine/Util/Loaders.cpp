#include "Loaders.h"

#define TINYOBJLOADER_IMPLEMENTATION
#include "../Resources/tiny_obj_loader.h"

namespace vn
{
	Mesh vn::loadMeshFromObj(const std::string & filepath)
	{
		{
			tinyobj::attrib_t attributes;
			std::vector<tinyobj::shape_t> shapes;
			std::vector<tinyobj::material_t> materials;
			std::string errors;
			Mesh objMesh;

			if (!tinyobj::LoadObj(&attributes, &shapes, &materials, &errors, filepath.c_str()))
			{
				std::cout << errors << std::endl;
			}
			unsigned int indices = 1;
			for (const auto& shape : shapes)
			{
				for (const auto& index : shape.mesh.indices)
				{
					Vertex vert;
					
					vert.position = vec3
					{
						attributes.vertices[3 * index.vertex_index + 0],
						attributes.vertices[3 * index.vertex_index + 1],
						attributes.vertices[3 * index.vertex_index + 2]
					};

					vert.uv = vec2
					{
						attributes.texcoords[2 * index.texcoord_index + 0],
						attributes.texcoords[2 * index.texcoord_index + 1]
					};

					vert.normal = vec3
					{
						attributes.normals[3 * index.normal_index + 0],
						attributes.normals[3 * index.normal_index + 1],
						attributes.normals[3 * index.normal_index + 2]
					};
					
					objMesh.vertices.emplace_back(vert);
					objMesh.indicies.emplace_back(indices++);
				}
			}

			return objMesh;
		}
	}
}