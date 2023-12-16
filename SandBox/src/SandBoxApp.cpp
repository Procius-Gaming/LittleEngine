#include <Little.h>

class ExampleLayer : public Little::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.0f, 1.0f, -1.0f, 1.0f), m_CameraPosition(0.0f, 0.0f, 0.0f)
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

			out vec3 v_Position;
			out vec4 v_Color;
			
			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
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
			
			void main()
			{
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
			
		)";

		std::string fragmentSrc2 = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			
			void main()
			{
				color = vec4(0.2, 0.3, 0.8, 1.0);
			}
			
		)";

		m_Shader2.reset(new Little::Shader(vertexSrc2, fragmentSrc2));
		
	}

	void OnUpdate() override
	{
		Little::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1});
		Little::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Little::Renderer::BeginScene(m_Camera);
		
		Little::Renderer::Submit(m_Shader2, m_SquareVA);
		Little::Renderer::Submit(m_Shader, m_VertexArray);

		Little::Renderer::EndScene();

		if (Little::Input::IsKeyPressed(LE_KEY_LEFT))
			m_CameraPosition.x -= m_cameraSpeed;
		else if (Little::Input::IsKeyPressed(LE_KEY_RIGHT))
			m_CameraPosition.x += m_cameraSpeed;

		if (Little::Input::IsKeyPressed(LE_KEY_UP))
			m_CameraPosition.y -= m_cameraSpeed;
		else if (Little::Input::IsKeyPressed(LE_KEY_DOWN))
			m_CameraPosition.y += m_cameraSpeed;

		if (Little::Input::IsKeyPressed(LE_KEY_Q))
			m_CameraRotation -= m_CameraRotationSpeed;
		else if ( Little::Input::IsKeyPressed(LE_KEY_E))
			m_CameraRotation += m_CameraRotationSpeed;
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
	float m_cameraSpeed = 0.1f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 0.5f;
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

