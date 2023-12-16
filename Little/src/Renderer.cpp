#include "lepch.h"
#include "Renderer/Renderer.h"


namespace Little {

  Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData; 

	void Renderer::BeginScene(OrthographicCamera& camera)
	{
    m_SceneData->ViewProjectionMatrix = camera.GetViewPojectionMatrix();
	}

  void Renderer::EndScene()
  {
  }

  void Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray> &vertexArray)
  {
    shader->Bind();
    shader->UploadUniformMat4("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
	  vertexArray->Bind();
	  RenderCommand::DrawIndexed(vertexArray);
  }
}