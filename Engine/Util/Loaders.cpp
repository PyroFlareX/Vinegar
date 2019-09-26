#include "Loaders.h"

#define TINYOBJLOADER_IMPLEMENTATION
#include "../Resources/tiny_obj_loader.h"

namespace vn
{
	Mesh vn::loadMeshFromObj(const std::string& filepath)
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
			/*unsigned int indices = 0;
			for (const auto& shape : shapes)
			{
				for (const auto& index : shape.mesh.indices)
				{
					Vertex vert;
					
					vert.position = 
					{
						attributes.vertices[3 * index.vertex_index + 0],
						attributes.vertices[3 * index.vertex_index + 1],
						attributes.vertices[3 * index.vertex_index + 2]
					};

					vert.uv =
					{
						attributes.texcoords[2 * index.texcoord_index + 0],
						attributes.texcoords[2 * index.texcoord_index + 1]
					};
					
					vert.normal =
					{
						attributes.normals[3 * index.normal_index + 0],
						attributes.normals[3 * index.normal_index + 1],
						attributes.normals[3 * index.normal_index + 2]
					};
					
					objMesh.vertices.push_back(vert);
					objMesh.indicies.push_back(++indices);
					indices++;
				}
			}*/

			// Loop over shapes
			for (size_t s = 0; s < shapes.size(); s++) {
				// Loop over faces(polygon)
				size_t index_offset = 0;
				for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
					int fv = shapes[s].mesh.num_face_vertices[f];

					// Loop over vertices in the face.
					for (size_t v = 0; v < fv; v++) {
						// access to vertex

						tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];

						Vertex vert;

						vert.position = vec3
						{
						attributes.vertices[3 * idx.vertex_index + 0],
						attributes.vertices[3 * idx.vertex_index + 1],
						attributes.vertices[3 * idx.vertex_index + 2] 
						};

						/*vert.normal = vec3
						{
						attributes.normals[3 * idx.normal_index + 0],
						attributes.normals[3 * idx.normal_index + 1],
						attributes.normals[3 * idx.normal_index + 2]
						};*/

						vert.uv = vec2
						{
						attributes.texcoords[2 * idx.texcoord_index + 0],
						attributes.texcoords[2 * idx.texcoord_index + 1]
						};

						objMesh.vertices.push_back(vert);
						objMesh.indicies.push_back(objMesh.indicies.size());
						// Optional: vertex colors
						// tinyobj::real_t red = attrib.colors[3*idx.vertex_index+0];
						// tinyobj::real_t green = attrib.colors[3*idx.vertex_index+1];
						// tinyobj::real_t blue = attrib.colors[3*idx.vertex_index+2];
					}
					index_offset += fv;

					// per-face material
					shapes[s].mesh.material_ids[f];
				}
			}

			return objMesh;
		}
	}
}