/*
 * Copyright (C) 2018 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef IGNITION_GAZEBO_SYSTEMS_OMNIDRIVE_HH_
#define IGNITION_GAZEBO_SYSTEMS_OMNIDRIVE_HH_

#include <memory>

#include <ignition/gazebo/System.hh>

namespace ignition
{
namespace gazebo
{
// Inline bracket to help doxygen filtering.
inline namespace IGNITION_GAZEBO_VERSION_NAMESPACE {
namespace systems
{
  // Forward declaration
  class OmniDrivePrivate;

  /// \brief 
  ///
  /// # System Parameters
  ///
  /// `<odom_publish_frequency>`: Odometry publication frequency. This
  /// element is optional, and the default value is 50Hz.
  ///
  /// `<topic>`: Custom topic that this system will subscribe to in order to
  /// receive command velocity messages. This element if optional, and the
  /// default value is `/model/{name_of_model}/cmd_vel`.
  ///
  /// `<odom_topic>`: Custom topic on which this system will publish odometry
  /// messages. This element if optional, and the default value is
  /// `/model/{name_of_model}/odometry`.
  class IGNITION_GAZEBO_VISIBLE OmniDrive
      : public System,
        public ISystemConfigure,
        public ISystemPreUpdate,
        public ISystemPostUpdate
  {
    /// \brief Constructor
    public: OmniDrive();

    /// \brief Destructor
    public: ~OmniDrive() override = default;

    // Documentation inherited
    public: void Configure(const Entity &_entity,
                           const std::shared_ptr<const sdf::Element> &_sdf,
                           EntityComponentManager &_ecm,
                           EventManager &_eventMgr) override;

    // Documentation inherited
    public: void PreUpdate(
                const ignition::gazebo::UpdateInfo &_info,
                ignition::gazebo::EntityComponentManager &_ecm) override;

    // Documentation inherited
    public: void PostUpdate(
                const UpdateInfo &_info,
                const EntityComponentManager &_ecm) override;

    /// \brief Private data pointer
    private: std::unique_ptr<OmniDrivePrivate> dataPtr;
  };
  }
}
}
}

#endif
