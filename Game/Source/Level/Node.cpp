#include <Level/Node.hpp>
#include <Entity/Impl/BaseEntity.hpp>


#define BUCKET_CAPACITY 32
#define CHILD_CAPACITY 4 // should always be 4

Node::Node()
: m_rectangle(), m_entity(), m_leafAvailable(true)
{
	m_child[0] = nullptr;
	m_child[1] = nullptr;
	m_child[2] = nullptr;
	m_child[3] = nullptr;
}

Node::~Node()
{

}

void Node::Initialize(sf::FloatRect p_rectangle)
{
	m_rectangle = p_rectangle;
}

void Node::AddEntity(BaseEntity* p_entity)
{
	if (p_entity == nullptr)
		return;
	if(m_rectangle.intersects(p_entity->GetCollisionRectangle()) == true)
	{
		if (m_leafAvailable == false)
		{
			MoveOneEntityDown(p_entity);
		}
		if (m_leafAvailable == true)
		{
			if(m_entity.size() >= BUCKET_CAPACITY)
			{				
				Subdivide();
				MoveOneEntityDown(p_entity);		
			}
			else
				m_entity.push_back(p_entity);
		}
	}
}


std::vector<BaseEntity*>* Node::FindNearObjects(sf::FloatRect rectangle, std::vector<BaseEntity*>* destinationVector)
{
	std::vector<BaseEntity*>* returnVector = new std::vector<BaseEntity*>; // delete this again
	if (m_rectangle.intersects(rectangle) == true)
	{
		returnVector->insert(returnVector->begin(), m_entity.begin(), m_entity.end());
		if (m_leafAvailable == false)
		{
			for(unsigned int i = 0; i < CHILD_CAPACITY; i++)
			{
				m_child[i]->FindNearObjects(rectangle, returnVector);
			}
		}
	}
	return returnVector;
}

void Node::Subdivide()
{
	// Make sure everythings already initalized when you start
	for(unsigned int i = 0; i < CHILD_CAPACITY; i++)
	{
		if(m_child[i] == nullptr)
		{
			m_child[i] = new Node();
			m_child[i]->Initialize(CalculateRectangleForchild(i));
		}
	}
	m_leafAvailable = false;
}

void Node::MoveOneEntityDown(BaseEntity* p_entity)
{
	for(unsigned int i = 0; i < CHILD_CAPACITY; i++)
	{
		m_child[i]->AddEntity(p_entity);
	}
}

sf::FloatRect Node::CalculateRectangleForchild(unsigned int p_index)
{
	sf::FloatRect l_returnRectangle = m_rectangle;

	// All subrectangles are half size in both width and height
	l_returnRectangle.width /= 2;
	l_returnRectangle.height /= 2;

	if(p_index == 0) // TopLeft
	{
		return l_returnRectangle; // No other movements are required
	}
	else if(p_index == 1) // TopRight
	{
		l_returnRectangle.left += l_returnRectangle.width; 
	}
	else if(p_index == 2) // Bot Left
	{
		l_returnRectangle.top += l_returnRectangle.height; 
	}
	else if(p_index == 3) // Bot right
	{
		l_returnRectangle.left += l_returnRectangle.width;
		l_returnRectangle.top += l_returnRectangle.height;
	}
	else
	{
		// Something is wrong, should not be able to enter here
		l_returnRectangle.width = 0;
		l_returnRectangle.height = 0;
	}
	return l_returnRectangle;
}
