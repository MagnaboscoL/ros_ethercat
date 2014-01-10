/*
 * ros_ethercat.hpp
 *
 *  Created on: 7 Jan 2014
 *      Author: Manos Nikolaidis
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2013, Shadow Robot Company Ltd.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

#ifndef SR_ETHERCAT_INTERFACE_HPP_
#define SR_ETHERCAT_INTERFACE_HPP_

#include <string>
#include <vector>
#include <ros/ros.h>
#include <hardware_interface/robot_hw.h>
#include <pr2_mechanism_model/robot.h>
#include <tinyxml.h>
#include <controller_manager/controller_manager.h>
#include <ethercat_hardware/ethercat_hardware.h>

class ros_ethercat : public hardware_interface::RobotHW
{
public:
  ros_ethercat(pr2_hardware_interface::HardwareInterface *hw, ros::NodeHandle nh) :
    model_(hw),
    state_(NULL),
    cm_node_(nh, "controller_manager")
  {}

  virtual ~ros_ethercat()
  {
    delete state_;
  }

  bool initXml(TiXmlElement* config);

  pr2_mechanism_model::Robot model_;
  pr2_mechanism_model::RobotState *state_;

private:
  ros::NodeHandle cm_node_;
};

#endif /* SR_ETHERCAT_INTERFACE_HPP_ */
