#include <Little.h>

#include <glm/gtc/matrix_transform.hpp>

class ExampleLayer : public Little::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.0f, 1.0f, -1.0f, 1.0f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(Little::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		std::shared_ptr<Little::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Little::VertexBuffer::Create(vertices, sizeof(vertices)));

		Little::BufferLayout layout = {
			{Little::ShaderDataType::Float3, "a_Position"},
			{Little::ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<Little::IndexBuffer> indexBuffer;
		indexBuffer.reset(Little::IndexBuffer::Create(indices, 3));
		m_VertexArray->SetIndexBuffer(indexBuffer);
		
		m_SquareVA.reset(Little::VertexArray::Create());

		float squareVertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		std::shared_ptr<Little::VertexBuffer> squareVB;
		squareVB.reset(Little::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

		squareVB->SetLayout({
			{Little::ShaderDataType::Float3, "a_Position"}
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Little::IndexBuffer> squareIB;
		squareIB.reset(Little::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;
			
			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
			
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;
			
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
			
		)";

		m_Shader.reset(new Little::Shader(vertexSrc, fragmentSrc));

		std::string vertexSrc2 = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;
			
			void main()
			{
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
			
		)";

		std::string fragmentSrc2 = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			
			uniform vec4 u_Color;
			
			void main()
			{
				color = u_Color;
			}
			
		)";

		m_Shader2.reset(new Little::Shader(vertexSrc2, fragmentSrc2));
		
	}

	void OnUpdate(Little::Timestep ts) override
	{
		LE_TRACE("Delta time: {0}s, ({1}s)", ts.GetSeconds(), ts.GetMiliseconds());

		Little::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1});
		Little::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Little::Renderer::BeginScene(m_Camera);

		glm::vec4 redColor(0.8f, 0.2f, 0.3f, 1.0f);
		glm::vec4 blueColor(0.2f, 0.3f, 0.8f, 1.0f);
		static glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		Little::Material* material = new Little::Material(m_Shader2);
		
		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				if (x % 2 == 0)
					m_Shader2->UploadUniformFloat4("u_Color", redColor);
				else
					m_Shader2->UploadUniformFloat4("u_Color", blueColor);
				Little::Renderer::Submit(m_Shader2, m_SquareVA, transform);
			}
		}

		Little::Renderer::Submit(m_Shader, m_VertexArray);

		Little::Renderer::EndScene();

		if (Little::Input::IsKeyPressed(LE_KEY_LEFT))
			m_CameraPosition.x -= m_cameraSpeed * ts;
		else if (Little::Input::IsKeyPressed(LE_KEY_RIGHT))
			m_CameraPosition.x += m_cameraSpeed * ts;

		if (Little::Input::IsKeyPressed(LE_KEY_UP))
			m_CameraPosition.y += m_cameraSpeed * ts;
		else if (Little::Input::IsKeyPressed(LE_KEY_DOWN))
			m_CameraPosition.y -= m_cameraSpeed * ts;

		if (Little::Input::IsKeyPressed(LE_KEY_Q))
			m_CameraRotation -= m_CameraRotationSpeed * ts;
		else if ( Little::Input::IsKeyPressed(LE_KEY_E))
			m_CameraRotation += m_CameraRotationSpeed * ts;

	}

	void OnImGuiRender() override
	{

	}

	void OnEvent(Little::Event& event) override
	{
		
	}
private:
	std::shared_ptr<Little::Shader> m_Shader;
	std::shared_ptr<Little::VertexArray> m_VertexArray;

	std::shared_ptr<Little::Shader> m_Shader2;
	std::shared_ptr<Little::VertexArray> m_SquareVA;

	Little::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_cameraSpeed = 5.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;

};




class SandBox : public Little::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
    }

	~SandBox()
	{
	}
};

Little::Application* Little::CreateApplication()
{
	return new SandBox();
}

