#ifndef OWDS_ARTRACKPERCEPTIONMODULE_H
#define OWDS_ARTRACKPERCEPTIONMODULE_H

#include "overworld/BasicTypes/Object.h"
#include "overworld/BasicTypes/Agent.h"
#include "overworld/Perception/PerceptionModuleBase.h"

#include "ar_track_alvar_msgs/AlvarMarkers.h"
#include "ar_track_alvar_msgs/AlvarVisibleMarkers.h"

namespace owds {

class ArTrackPerceptionModule : public PerceptionModuleRosSyncBase<Object, ar_track_alvar_msgs::AlvarMarkers, ar_track_alvar_msgs::AlvarVisibleMarkers>
{
public:
  ArTrackPerceptionModule(ros::NodeHandle* n, Agent* agent = nullptr);

  void setAgent(Agent* agent) { agent_ = agent; }

private:
  Agent* agent_;
  Pose last_head_pose_;

  bool perceptionCallback(const ar_track_alvar_msgs::AlvarMarkers& markers,
                          const ar_track_alvar_msgs::AlvarVisibleMarkers& visible_markers);

  bool headHasMoved();
  bool isInValidArea(const Pose& tag_pose);
};

} // namespace owds

#endif // OWDS_ARTRACKPERCEPTIONMODULE_H