#pragma once
#include "Component.h"

class CSpriteRenderer;
class CTransform;
class CCollider;
class Component;
class GameObject
{
	friend class ObjectManager;

private:
	bool m_IsDestroy = false;
	list<Component*> m_Components;

protected:
	OBJTAG* collisionCheckList = nullptr;

public:
	GameObject* gameObject = nullptr;

	CSpriteRenderer* spriteRenderer;
	CTransform*	transform;
	Vec2 normalizeVector;
	CCollider* collider;
	string name;
	OBJTAG tag;

	bool activeSelf = true;
	float velocity;

public:
	GameObject();
	virtual ~GameObject();

	void SetActive(bool active) { activeSelf = active; }
	void Destroy() { m_IsDestroy = true; }

	bool IsDestroy() const { return m_IsDestroy; }
	bool InSideScreen();

	bool CompareTag(OBJTAG _tag) { return (tag == _tag); }

	list<Component*>& GetComponents() { return m_Components; }

	template <typename T>
	T* GetComponent()
	{
		if (std::is_base_of<Component, T>::value == TRUE)
		{
			for (auto iter : m_Components)
				if (typeid(T) == typeid(*iter))
					return static_cast<T*>(iter);
		}
		return nullptr;
	}

	template <typename T>
	T* AddComponent()
	{
		if (FALSE == std::is_base_of<Component, T>::value)
			return nullptr;

		if (nullptr != this->GetComponent<T>())
			return this->GetComponent<T>();

		T* pComponent = new T();

		pComponent->gameObject = this;
		pComponent->enabled = true;

		m_Components.emplace_back(pComponent);

		return pComponent;
	}

private:
	virtual void Update()							PURE;
	virtual void Render()							PURE;
	virtual void Release()							PURE;
	virtual void OnTriggerEnter2D(GameObject* obj)	PURE;
	virtual void OnTriggerStay2D(GameObject* obj)	PURE;
	virtual void OnTriggerExit2D(GameObject* obj)	PURE;

	void ComponentsUpdate();
	void ComponentsRender();
	void ComponemtsRelease();

	bool GetObjectCollisionCheckResult(GameObject* other);
	CollisionDetectedType GetCollisionDetectedType(GameObject* other);
};

