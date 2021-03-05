#include "dkpch.h"

#include "Renderer.h"

namespace Dark {

  Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData;

  void Renderer::BeginScene(OrthographicCamera& camera)
  {
	m_SceneData->ViewProjectMatrix = camera.GetViewProjectionMatrix();
  }

  void Renderer::EndScene()
  {
  }

  void Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray)
  {
	shader->use();
	shader->UploadUniformMat4("u_ViewProjection", m_SceneData->ViewProjectMatrix);
	vertexArray->Bind();
	RenderCommand::DrawIndexed(vertexArray);
  }

}