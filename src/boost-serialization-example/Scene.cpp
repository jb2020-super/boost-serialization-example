#include "Scene.h"

namespace jb2020
{
	size_t Scene::GetGOCount() const noexcept
	{
		return m_gos.size();
	}
	IGameObject* Scene::GetGO(int idx)
	{
		if (idx >= 0 && idx < m_gos.size()) {
			return m_gos[idx].get();
		}
		return nullptr;
	}
	void Scene::Release()
	{
		delete this;
	}
	void Scene::PushBack(IGameObject* go)
	{
		std::unique_ptr<IGameObject> pgo(go);
		m_gos.push_back(std::move(pgo));
	}
	Scene::~Scene()
	{
	}
	Scene::Scene()
	{
	}
}