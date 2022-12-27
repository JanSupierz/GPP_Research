#ifndef INFLUENCE_MAP_APPLICATION_H
#define INFLUENCE_MAP_APPLICATION_H
//-----------------------------------------------------------------
// Includes & Forward Declarations
//-----------------------------------------------------------------
#include "framework/EliteInterfaces/EIApp.h"
#include "projects/Movement/SteeringBehaviors/SteeringHelpers.h"

#include "framework\EliteAI\EliteGraphs\EliteGraphUtilities\EGraphRenderer.h"
#include "framework\EliteAI\EliteNavigation\Algorithms\EPathSmoothing.h"

class NavigationColliderElement;
class UnitAgent;
class Seek;
class Arrive;
class Group;

namespace Elite
{
	class NavGraph;
}
//-----------------------------------------------------------------
// Application
//-----------------------------------------------------------------
class App_NavMeshGraph final : public IApp
{
public:
	//Constructor & Destructor
	App_NavMeshGraph() = default;
	virtual ~App_NavMeshGraph();

	//App Functions
	void Start() override;
	void Update(float deltaTime) override;
	void Render(float deltaTime) const override;

private:
	//Datamembers
	
	// --Groups--
	Group* m_pGroup = nullptr;
	
	// --Agents--
	std::vector<UnitAgent*> m_pAgents{};
	const int m_NrAgents{ 20 };

	TargetData m_Target = {};
	float m_AgentRadius = 1.0f;
	float m_AgentSpeed = 16.0f;

	// --Level--
	std::vector<NavigationColliderElement*> m_vNavigationColliders = {};

	// --Selection--
	Elite::Vector2 m_StartSelectionPos{};
	Elite::Vector2 m_EndSelectionPos{};

	std::vector<Elite::Vector2> m_SelectionPoints;
	Elite::Color m_SelectionColor{ 0.f,0.f,1.f };

	bool m_IsSelecting{ false };

	// --Graph--
	Elite::NavGraph* m_pNavGraph = nullptr;
	Elite::GraphRenderer m_GraphRenderer{};

	// --Debug drawing information--
	std::vector<Elite::Portal> m_Portals;
	std::vector<Elite::Vector2> m_DebugNodePositions;
	std::vector<Elite::Vector2> m_VisitedNodePositions;
	static bool sShowPolygon;
	static bool sShowGraph;
	static bool sDrawPortals;
	static bool sDrawFinalPath;
	static bool sDrawNonOptimisedPath;
	static bool sDrawNodesUsedForAStar;

	void UpdateImGui();
private:
	//C++ make the class non-copyable
	App_NavMeshGraph(const App_NavMeshGraph&) = delete;
	App_NavMeshGraph& operator=(const App_NavMeshGraph&) = delete;
};
#endif